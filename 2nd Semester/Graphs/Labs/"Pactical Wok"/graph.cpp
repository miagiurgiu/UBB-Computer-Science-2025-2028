#include "graph.h"
#include <stdexcept>
#include <fstream>
#include <random>
#include <queue>
#include <algorithm>
#include <utility>

/*
1. Internal Representation:
Adjacency List: Implemented using a std::vector of std::unordered_map. This allows O(1) access to a vertex's neighbors.
Edge Objects: Edges are stored as pointers to Edge structs. This allows the inbound and outbound maps to point to the same object in memory, making cost modifications instant for both directions.
Memory Management: Implemented the Rule of Three (Destructor, Copy Constructor, Assignment Operator) to manage raw pointers and prevent memory leaks.

2. Complexity Table:
| Operation | Complexity |
| add_edge / remove_edge | O(1) average |
| is_edge | O(1) average |
| get_in_degree / get_out_degree | O(1) |
| remove_vertex | O(deg(v)) |

3. Memory Management & The Rule of Three

Because the graph uses raw pointers (Edge*) to ensure the inbound and outbound maps point to the same data, we implemented:
Destructor: Properly deletes every edge pointer to prevent memory leaks when the graph is destroyed.
Copy Constructor: Performs a Deep Copy. It creates entirely new Edge objects in memory so that modifying a copy of a graph doesn't change the original.
Assignment Operator: Handles self-assignment and clears existing memory before copying new data.

4. Performance Comparison
Python: Easier to write, but slower for the graph100k.txt file due to overhead.
C++: Significantly faster for large files. The std::unordered_map provides the same O(1) average time complexity as Python dictionaries but with better raw execution speed.
*/

// 1. Default Constructor
// explicit Graph(int n) - creates a graph with n vertices 
Graph::Graph(int n) : nr_vertices(n), nr_edges(0) {
    outbound.resize(n);
    inbound.resize(n);
}

// 2. Copy Constructor (Deep Copy)
// Graph(const Graph& other) - performs a deep copy of all edge objects
Graph::Graph(const Graph& other) {
    this->nr_vertices = other.nr_vertices;
    this->nr_edges = other.nr_edges;
    this->outbound.resize(other.nr_vertices);
    this->inbound.resize(other.nr_vertices);

    for (int i = 0; i < other.nr_vertices; i++) {
        for (auto const& [target, old_edge_ptr] : other.outbound[i]) {
            Edge_id new_edge = new Edge{old_edge_ptr->source, old_edge_ptr->target, old_edge_ptr->cost};
            this->outbound[i][target] = new_edge;
            this->inbound[target][i] = new_edge;
        }
    }
}

// 3. Assignment Operator
// Graph& operator = (const Graph& other)
Graph& Graph::operator=(const Graph& other) {
    if (this == &other) return *this;

    // Clean old memory
    for (int i = 0; i < nr_vertices; i++) {
        for (auto const& [target, edge_ptr] : outbound[i]) {
            delete edge_ptr;
        }
    }

    // Rebuild
    this->nr_vertices = other.nr_vertices;
    this->nr_edges = other.nr_edges;
    this->outbound.assign(other.nr_vertices, {});
    this->inbound.assign(other.nr_vertices, {});

    for (int i = 0; i < other.nr_vertices; i++) {
        for (auto const& [target, old_edge_ptr] : other.outbound[i]) {
            Edge_id new_edge = new Edge{old_edge_ptr->source, old_edge_ptr->target, old_edge_ptr->cost};
            this->outbound[i][target] = new_edge;
            this->inbound[target][i] = new_edge;
        }
    }
    return *this;
}

// 4. Destructor
// ~Graph()
Graph::~Graph() {
    for (int i = 0; i < nr_vertices; i++) {
        for (auto const& [target, edge_ptr] : outbound[i]) {
            delete edge_ptr;
        }
    }
}

// basic methods

int Graph::get_nr_vertices() const {
    return nr_vertices;
}

int Graph::get_nr_edges() const {
    return nr_edges;
}

// add a vertex (default next id)
void Graph::add_vertex() {
    outbound.push_back({});
    inbound.push_back({});
    nr_vertices++;
}

// remove vertex
void Graph::remove_vertex(int v) {
    if (v < 0 || v >= nr_vertices)
        return;

    Graph rebuilt(nr_vertices - 1);

    for (int old_source = 0; old_source < nr_vertices; old_source++) {
        if (old_source == v)
            continue;

        for (auto const& [old_target, edge_ptr] : outbound[old_source]) {
            if (old_target == v)
                continue;

            int new_source = old_source;
            int new_target = old_target;

            if (old_source > v)
                new_source--;
            if (old_target > v)
                new_target--;

            rebuilt.add_edge(new_source, new_target, edge_ptr->cost);
        }
    }

    *this = rebuilt;
}

// edge methods

bool Graph::is_edge(int u, int v) const {
    if (u < 0 || u >= nr_vertices) 
        return false;
    return outbound[u].count(v) > 0;
}

Graph::Edge_id Graph::get_edge_id(int u, int v) const {
    if (is_edge(u, v)) {
        return outbound[u].at(v);
    }
    return nullptr;
}

void Graph::add_edge(int u, int v, int cost) {
    if (u < 0 || u >= nr_vertices || v < 0 || v >= nr_vertices)
        throw std::out_of_range("Vertex index out of bounds");

    if (is_edge(u, v)) 
        return;


    Edge_id new_edge = new Edge{u, v, cost};
    outbound[u][v] = new_edge;
    inbound[v][u] = new_edge;
    nr_edges++;
}

void Graph::remove_edge(int u, int v) {
    if (!is_edge(u, v)) return;
    Edge_id edge_to_del = outbound[u][v];
    outbound[u].erase(v);
    inbound[v].erase(u);
    delete edge_to_del;
    nr_edges--;
}

// degree methods

int Graph::get_in_degree(int v) const {
    if (v < 0 || v >= nr_vertices)
        throw std::out_of_range("Vertex index out of bounds");
    return (int)inbound[v].size();
}

int Graph::get_out_degree(int v) const {
    if (v < 0 || v >= nr_vertices) 
        throw std::out_of_range("Vertex index out of bounds");
    return (int)outbound[v].size();
}

// iterator methods

const std::unordered_map<int, Graph::Edge_id>& Graph::parse_out(int v) const {
    if (v < 0 || v >= nr_vertices) 
        throw std::out_of_range("Vertex index out of bounds");
    return outbound[v];
}

const std::unordered_map<int, Graph::Edge_id>& Graph::parse_in(int v) const {
    if (v < 0 || v >= nr_vertices) 
        throw std::out_of_range("Vertex index out of bounds");
    return inbound[v];
}

Graph read_from_file(const std::string& filename) {
    std::ifstream f(filename);
    if(!f.is_open())
        throw std::runtime_error("Could not open file");

    int n,m;
    f>>n>>m;
    Graph g(n);
    for (int i=0; i<m; i++) {
        int u,v,c;
        f>>u>>v>>c;
        g.add_edge(u,v,c);
    }
    return g;
}

void write_to_file(const Graph& g, const std::string& filename) {
    std::ofstream f(filename);
    if (!f.is_open()) throw std::runtime_error("Could not open file for writing");

    int n = g.get_nr_vertices();
    // We need to find the actual number of edges to write the header correctly
    int edge_count = 0;
    for (int i = 0; i < n; i++) {
        edge_count += g.get_out_degree(i);
    }

    f << n << " " << edge_count << "\n";
    for (int i = 0; i < n; i++) {
        for (auto const& [target, edge] : g.parse_out(i)) {
            f << i << " " << target << " " << edge->cost << "\n";
        }
    }
}

Graph create_random_graph(int n, int m) {
    // Cap edges at n * n
    long long max_edges = (long long)n * n;
    if (m > max_edges) {
        m = (int)max_edges;
    }

    Graph g(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n - 1);
    
    int count = 0;
    while (count < m) { 
        int u = dis(gen);
        int v = dis(gen);
        if (!g.is_edge(u, v)) {
            g.add_edge(u, v, rand() % 100);
            count++;
        }
    }
    return g;
}

// bfs traversal
// s - starting vertex
// t - ending vertex
BFSResult bfs(const Graph& g, int s, int t) {
    // validations ensure the vertex exists 
    if (s < 0 || s >= g.get_nr_vertices())
        throw std::out_of_range("Start vertex out of bounds");
    if (t != -1 && (t < 0 || t >= g.get_nr_vertices()))
        throw std::out_of_range("Target vertex out of bounds");

    BFSResult result; // container of the output
    std::queue<int> q; // queue that follows fifo - ensures we visit vertices in the order they were discovered
    std::unordered_set<int> visited; // set that keeps track of which nodes were already processed

    result.distance[s] = 0; // distance to the start node is 0
    result.parent[s] = -1;   // equivalent of None in Python // parent of the start node - root

    q.push(s); // add the start node to the queue
    visited.insert(s); // mark it as visited

    while (!q.empty()) { // as long as there are vertices in the queue
        int x = q.front(); // take the first one (current node)
        q.pop(); // remove it

        for (auto const& [y, edge] : g.parse_out(x)) { // iterate through every neighbour y connected to x via outbound edge
            if (visited.find(y) == visited.end()) { // if we have not visited neighbour y before
                q.push(y); // add it to queue to explore its neighbours later
                result.distance[y] = result.distance[x] + 1; // set its distance
                result.parent[y] = x; // set its parent
                visited.insert(y); // mark as visited

                if (y == t) // early exit
                    return result;
            }
        }
    }
    return result;
}

// determine shortest path
// s - starting vertex
// t - ending vertex
std::vector<int> shortest_path(const Graph& g, int s, int t) {
    BFSResult result = bfs(g, s, t); // calls the bfs function to populate the distance and parent maps

    if (result.distance.find(t) == result.distance.end()) // if t is not in the distance map, there is no path from s to t
        return {}; // return the empty vector

    // backtracking: start at t and use parent to walk backward to s.
    // ex: 1->2->6, parents: parent[6]=2, parent[2]=1
    std::vector<int> path;
    int vertex = t; // start 

    while (vertex != s) { // while not reached the starting vertex
        path.push_back(vertex); // add current vertex to path
        vertex = result.parent[vertex]; // vertex variable updates with the parent of the current vertex
    }

    path.push_back(s); // add the starting vertex
    std::reverse(path.begin(), path.end()); // reverse to correct order

    return path;
}

/// time complexity: O(n+m), n=nr of vertices; m=nr of edges
/// - we visit each vertex once; we check each edge once
/// space complexity
/// - O(n) to store the visited set, the queue and the BFSResult maps.


// 1. First pass to fill the stack based on finishing times
void dfs_first_pass(int v, const Graph& g, std::unordered_set<int>& visited, std::vector<int>& stack) {
    visited.insert(v);
    for (auto const& [neighbor, edge] : g.parse_out(v)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs_first_pass(neighbor, g, visited, stack);
        }
    }
    stack.push_back(v); // Push to stack when finished
}

// 2. Second pass on the transposed graph (using parse_in)
void dfs_second_pass(int v, const Graph& g, std::unordered_set<int>& visited, std::vector<int>& current_scc) {
    visited.insert(v);
    current_scc.push_back(v);
    for (auto const& [neighbor, edge] : g.parse_in(v)) { // Transpose logic
        if (visited.find(neighbor) == visited.end()) {
            dfs_second_pass(neighbor, g, visited, current_scc);
        }
    }
}

// bonus hw2
SCCResult find_sccs(const Graph& g) {
    std::vector<int> stack;
    std::unordered_set<int> visited;
    int n = g.get_nr_vertices();

    // Step 1: Fill stack with finishing times
    for (int i = 0; i < n; i++) {
        if (visited.find(i) == visited.end()) {
            dfs_first_pass(i, g, visited, stack);
        }
    }

    // Step 2: Process nodes in decreasing order of finishing time
    visited.clear();
    SCCResult all_sccs;
    
    // Iterate stack from back to front (mimics stack behavior)
    for (int i = (int)stack.size() - 1; i >= 0; i--) {
        int v = stack[i];
        if (visited.find(v) == visited.end()) {
            std::vector<int> current_scc;
            dfs_second_pass(v, g, visited, current_scc);
            all_sccs.push_back(current_scc);
        }
    }

    return all_sccs;
}

// BACKWARDS DIJKSTRA
DijkstraResult backwards_dijkstra(const Graph& g, int s, int t) {
    // stop conditions
    if (s < 0 || s >= g.get_nr_vertices())
        throw std::out_of_range("Start vertex out of bounds");
    if (t < 0 || t >= g.get_nr_vertices())
        throw std::out_of_range("Target vertex out of bounds");

    DijkstraResult result;

    // min-heap priority queue
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>> // flips the default priority queue which is usually max-heap
    > q;

    q.push({0,t}); // start from target
    result.dist[t] = 0; // distance from t to itself is 0
    bool found=false; // optimization (stop when we reach s)

    while (!q.empty() && !found) { // queue still has vertices + haven't reached s yet
        // extract best node
        int x = q.top().second; // current vertex
        int current_dist = q.top().first; // best known distance to current vertex
        q.pop();

        if (current_dist != result.dist[x]) // only process best distance for each vertex
            continue;

        for (auto const& [y,edge]:g.parse_in(x)) { // traverse inbound edges (y->x)
            if (result.dist.find(y)==result.dist.end() || result.dist[x]+edge->cost < result.dist[y]) { // relaxation step
                result.dist[y]=result.dist[x]+edge->cost; // update
                q.push({result.dist[y],y}); // add updated y to queue
                result.next[y]=x; // path (from y, the next step towards t is x)
            }
        }

        if (x==s)
            found = true;
    }
    return result;
}

// graph - read only
// s - start vertex
// t - target vertex
std::vector<int> lowest_cost_walk(const DijkstraResult& result, int s, int t) { // returns a list of vertices (the path)
    //DijkstraResult result = backwards_dijkstra(g, s, t); // run dijkstra
    // in result.dist -> costs to reach t
    // in result.next -> how to move towards t
    if (result.dist.find(s)==result.dist.end()) // no path from s to t
        return {}; // return the empty vector
    std::vector<int> path; // the result path (vector) built from the beginning
    int current = s;
    path.push_back(current); // s (start) is the first element - add vertex to the path
    while (current != t) { // loop until reached t (target)
        current=result.next.at(current); // go to the next vertex on the optimal path (next[0]=2, next[2]=5 => 0-2-5)
        path.push_back(current); // add vertex to the path
    }
    return path;
}

// Bonus: 2B:

// predecessor counting algorithm
std::vector<int> topological_sort(const Graph& g) {
    int n = g.get_nr_vertices();
    std::vector<int> sorted;
    std::vector<int> count(n); // how many predecessors x still has
    std::queue<int> q; // priority does not matter

    // compute in-degree for every vertex
    for (int x = 0; x < n; x++) { // visit every vertex
        count[x] = g.get_in_degree(x); // store nr of incoming edges
        if (count[x] == 0) { // vertices with no predecessors come first
            q.push(x);
        }
    }

    // process vertices with no remaining predecessors
    while (!q.empty()) { // as long as there are available vertices
        int x = q.front(); // save first vertex separately
        q.pop(); // remove it
        sorted.push_back(x); // add to final list

        for (const auto& [y, edge] : g.parse_out(x)) { // go through edges x->y
            count[y]--; // remove that edge x->y => y has one less remaining predecessor
            if (count[y] == 0) { // y is left with no predecessors
                q.push(y); // it can be processed
            }
        }
    }

    // if not all vertices were processed, graph has a cycle
    if ((int)sorted.size() < n) { // not all vertices were sorted => detected a cycle
        return {}; // graph has cycles
    }

    return sorted;
}

// counting the number of distinct walks = dp
long long count_distinct_walks_dag(const Graph& g, int s, int t) {
    int n = g.get_nr_vertices();

    if (s < 0 || s >= n || t < 0 || t >= n) {
        throw std::out_of_range("Vertex out of bounds");
    }

    std::vector<int> topo = topological_sort(g); // get topological order
    if (topo.empty() && n > 0) { // cycle
        throw std::runtime_error("Graph is not a DAG");
    }

    std::vector<long long> nr(n, 0); // number of ways to reach x
    nr[s] = 1;

    for (int x : topo) { // process vertices in topological order
        for (const auto& [y, edge] : g.parse_out(x)) { // x->y
            nr[y] += nr[x]; // every way to reach x creates a way to reach y
        }
    }

    return nr[t]; // number of ways to reach target
}

Graph build_min_cost_graph(const Graph& g, const DijkstraResult& result) {
    int n = g.get_nr_vertices();
    Graph good(n); // new graphs with same vertices but no edges yet

    for (int x = 0; x < n; x++) { // check every vertex
        for (auto const& [y, edge] : g.parse_out(x)) { // check every edge
            if (result.dist.find(x) != result.dist.end() && // x can reach y
                result.dist.find(y) != result.dist.end() && // y can reach t
                result.dist.at(x) == edge->cost + result.dist.at(y)) { // min-cost path
                good.add_edge(x, y, edge->cost); // keep this edge
                }
        }
    }

    return good;
}

/*
 * Returns:
 * min cost
 * nr of min cost walks
 * whether infinite
 * whether path exists
 */
MinCostWalkCountResult count_min_cost_walks(const Graph& g, int s, int t) {
    int n = g.get_nr_vertices();

    if (s < 0 || s >= n || t < 0 || t >= n) {
        throw std::out_of_range("Vertex out of bounds");
    }

    // Step 1: compute minimum costs to t
    DijkstraResult result = backwards_dijkstra(g, s, t);

    if (result.dist.find(s) == result.dist.end()) { // s cannot reach t
        return {0, 0, false, false}; // no path
    }

    // Step 2: keep only edges that preserve minimum cost
    Graph good = build_min_cost_graph(g, result);

    // Step 3: if the graph of minimum-cost edges has a cycle,
    // then there may be infinitely many minimum-cost walks.
    std::vector<int> topo = topological_sort(good); // checks if good has cycles

    if (topo.empty() && good.get_nr_vertices() > 0) { // has cycles
        return {result.dist.at(s), 0, true, true}; // there is a path, but nr of min cost walks is infinite.
        // THERE IS A PATH FROM S TO T BUT THERE ARE INFINITELY MANY WALKS (bc of cycles)
    }

    // Step 4: count distinct walks in this DAG
    long long nr = count_distinct_walks_dag(good, s, t);

    return {result.dist.at(s), nr, false, true};
}

/*
LongestPathResult longest_path_dag(const Graph& g) {
    int n = g.get_nr_vertices();
    if (n==0) {
        return {0,{}};
    }
    std::vector<int> topo=topological_sort(g);
    if ((int)topo.size()!=n) {
        throw std::runtime_error("Graph is not a DAG");
    }
    std::vector<int> w(n,0); // w[x] = length of the longest path ending in x
    std::vector<int> parent(n,-1); // parent[x] = previous vertex before x in the best path ending in x

    for (int x: topo) {
        for (const auto& [y,edge]: g.parse_out(x)) {
            if (w[x]+1>w[y]) {
                w[y]=w[x]+1;
                parent[y]=x;
            }
        }
    }
    int end_vertex=0;
    for (int x=1; x<n; x++) {
        if (w[x]>w[end_vertex]) {
            end_vertex=x;
        }
    }
    std::vector<int> path;
    int current=end_vertex;
    while (current !=-1) {
        path.push_back(current);
        current=parent[current];
    }
    std::reverse(path.begin(), path.end());
    return {w[end_vertex],path};
}
*/

// practical work 4
static bool topological_sort_dfs_visit(const Graph& g, int x, std::vector<int>& sorted, std::vector<bool>& fully_processed, std::vector<bool>& in_process) {
    in_process[x]=true; // x is currently being processed

    // go through all predecessors y of x, meaning all edges y->x
    for (const auto& [y,edge]: g.parse_in(x)) { // inbound neighbours of x
        if (in_process[y]) // if we encounter a node currently being processed
            return false; // we found a cycle => topological sort impossible on cyclic graphs
        if (!fully_processed[y]) { // y not visited yet
            bool ok=topological_sort_dfs_visit(g, y, sorted, fully_processed, in_process); // recurse into it
            if (!ok) { // any recursive call detects a cycle
                return false;
            }
        }
    }
    // all predecessors are finished
    in_process[x]=false; // remove x from recursion stack
    fully_processed[x]=true; // mark x as finished -> will never be processed again
    sorted.push_back(x); // put x in topological order
    return true;

    // we process predecessors first, so x appears after them
}

// ! main function
std::vector<int> topological_sort_dfs(const Graph& g) {
    int n = g.get_nr_vertices();
    std::vector<int> sorted;
    std::vector<bool> fully_processed(n,false); // track nodes that are completely finished
    std::vector<bool> in_process(n,false); // track nodes in the current dfs path
    for (int x=0; x<n; x++) { // loop through every vertex
        if (!fully_processed[x]) { // start new visit from x (because it was never touched by dfs)
            bool ok=topological_sort_dfs_visit(g, x, sorted, fully_processed, in_process);
            if (!ok) {
                return {};
            }
        }
    }
    return sorted;
}

HighestCostPathResult highest_cost_path_dag(const Graph& g, int s, int t) {
    int n = g.get_nr_vertices();
    if (s<0 || s>=n || t<0 || t>=n) {
        throw std::out_of_range("Vertex out of bounds");
    }
    std::vector<int> topo=topological_sort_dfs(g);
    if ((int)topo.size()!=n) {
        throw std::runtime_error("Graph is not a DAG");
    }

    std::vector<int> cost(n,0); // cost[x] - highest cost of a path from s to x

    std::vector<int> parent(n,-1); // parent[x] - previous vertex before x in the best path from s to x

    std::vector<bool> reachable(n,false); // reachable[x] - true if we already found a path from s to x

    reachable[s]=true;
    cost[s]=0;

    for (int x: topo) {
        if (!reachable[x]) {
            continue;
        }
        for (const auto& [y,edge]: g.parse_out(x)) {
            int new_cost=cost[x]+edge->cost;
            if (!reachable[y] || new_cost > cost[y]) {
                reachable[y]=true;
                cost[y]=new_cost;
                parent[y]=x;
            }
        }
    }

    if (!reachable[t]) {
        return {false, 0, {}};
    }

    std::vector<int> path;
    int current=t;
    while (current!=-1) {
        path.push_back(current);
        if (current==s) {
            break;
        }
        current=parent[current];
    }
    std::reverse(path.begin(), path.end());
    return {true,cost[t],path};
}

// bonus 2b
// counts every possible way to get from s to t
// if i am at vertex v, the number of ways to reach t from v is THE SUM of the ways to reach t from all of v's neighbours
long long count_distinct_paths(const Graph& g, int s, int t) {
    std::vector<int> topo = topological_sort_dfs(g); // Reuses your existing code

    // Check if the graph is a DAG
    if (topo.empty() && g.get_nr_vertices() > 0) {
        throw std::runtime_error("Error: Graph contains a cycle. This operation is only for DAGs.");
    }

    int n = g.get_nr_vertices();
    std::vector<long long> num_paths(n, 0);

    num_paths[s] = 1;

    for (int u : topo) {
        if (num_paths[u] > 0) {
            for (auto const& [v, edge] : g.parse_out(u)) {
                num_paths[v] += num_paths[u];
            }
        }
    }
    return num_paths[t];
}

// bonus 3b
// counts all lowest cost paths
std::pair<int, long long> count_lowest_cost_paths(const Graph& g, int s, int t) {
    std::vector<int> topo = topological_sort_dfs(g);

    // Check if the graph is a DAG
    if (topo.empty() && g.get_nr_vertices() > 0) {
        throw std::runtime_error("Error: Graph contains a cycle. This operation is only for DAGs.");
    }
    int n = g.get_nr_vertices();
    std::vector<int> min_dist(n, std::numeric_limits<int>::max());
    std::vector<long long> path_count(n, 0);

    min_dist[s] = 0;
    path_count[s] = 1;

    for (int u : topo) {
        if (min_dist[u] == std::numeric_limits<int>::max()) continue;

        for (auto const& [v, edge] : g.parse_out(u)) {
            if (min_dist[u] + edge->cost < min_dist[v]) { // we found a new best path
                min_dist[v] = min_dist[u] + edge->cost; // set to new value
                path_count[v] = path_count[u]; // reset count
            } else if (min_dist[u] + edge->cost == min_dist[v]) { // found an alternative path with the same minimum cost
                path_count[v] += path_count[u]; // add to count
            }
        }
    }
    return {min_dist[t], path_count[t]};
}