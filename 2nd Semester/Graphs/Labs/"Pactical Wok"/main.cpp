#include "graph.h"
#include <iostream>
#include <string>

void test_all();

void print_menu() {
    std::cout << "\n--- Graph Manager ---\n";
    std::cout << "1. Read graph from file\n";
    std::cout << "2. Write graph to file\n";
    std::cout << "3. Create random graph\n";
    std::cout << "4. Get number of vertices\n";
    std::cout << "5. Get number of edges\n";
    std::cout << "6. Add vertex\n";
    std::cout << "7. Remove vertex\n";
    std::cout << "8. Add edge\n";
    std::cout << "9. Remove edge\n";
    std::cout << "10. Check if edge exists\n";
    std::cout << "11. Get in degree\n";
    std::cout << "12. Get out degree\n";
    std::cout << "13. Parse vertices\n";
    std::cout << "14. Parse outbound edges\n";
    std::cout << "15. Parse inbound edges\n";
    std::cout << "16. Get edge cost\n";
    std::cout << "17. Modify edge cost\n";
    std::cout << "18. Copy graph\n";
    std::cout << "19. Find lowest length path (BFS)\n";
    std::cout << "20. (bonus) Find strongly-connected components of a directed graph\n";
    std::cout << "21. Find lowest cost walk (backwards Dijkstra)\n";
    std::cout << "22. (bonus 2b) Count distinct walks in DAG\n";
    std::cout << "23. (bonus 1b) Count distinct minimum-cost walks\n";
    std::cout << "24. Check if graph is DAG + topological sort (dfs) + highest cost path\n";
    std::cout << "25. (bonus 1b) Count distinct paths in DAG\n";
    std::cout << "26. (bonus 2b) Count lowest cost paths in DAG\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    test_all();
    Graph g(0); // Start empty
    int choice = -1;

    while (choice != 0) {
        print_menu();
        if (!(std::cin >> choice))
            break;
        try {
            switch (choice) {
                case 1: { // Read from file
                    std::string filename;
                    std::cout << "Enter filename (e.g., graph1k.txt): ";
                    std::cin >> filename;
                    g = read_from_file(filename);
                    std::cout << "Loaded " << g.get_nr_vertices() << " vertices.\n";
                    break;
                }
                case 2: { // Write to file
                    std::string filename;
                    std::cout << "Enter filename to save: ";
                    std::cin >> filename;
                    write_to_file(g, filename);
                    break;
                }
                case 3: { // Random
                    int n, m;
                    std::cout << "Enter n and m: ";
                    std::cin >> n >> m;
                    g = create_random_graph(n, m);
                    break;
                }
                case 4: {
                    std::cout << "Vertices: " << g.get_nr_vertices() << "\n";
                    break;
                }
                case 5: {
                    std::cout << "Edges: " << g.get_nr_edges() << "\n";
                    break;
                }
                case 6: {
                    g.add_vertex();
                    std::cout << "Added vertex " << g.get_nr_vertices()-1 << "\n";
                    break;
                }
                case 7: {
                    int v; std::cout << "Vertex to remove: "; std::cin >> v;
                    g.remove_vertex(v);
                    break;
                }
                case 8: {
                    int u, v, c; 
                    std::cout << "Start End Cost: "; 
                    std::cin >> u >> v >> c;
                    if (g.is_edge(u, v)) {
                        std::cout << "Edge already exists! Use Option 17 to modify cost.\n";
                    } 
                    else {
                        g.add_edge(u, v, c);
                        std::cout << "Edge " << u << "->" << v << " added successfully.\n";
                    }
                    break;
                }
                case 9: {
                    int u, v;
                    std::cout << "Start End: ";
                    std::cin >> u >> v;
                    if (g.is_edge(u, v)) {
                        g.remove_edge(u, v);
                        std::cout << "Edge " << u << "->" << v << " removed successfully.\n";
                    } 
                    else {
                        std::cout << "Error: Edge " << u << "->" << v << " does not exist.\n";
                    }
                    break;
                }
                case 10: {
                    int u, v;
                    std::cout << "Start End: "; 
                    std::cin >> u >> v;
                    std::cout << (g.is_edge(u, v) ? "Exists\n" : "Doesn't exist\n");
                    break;
                }
                case 11: {
                    int v; 
                    std::cout << "Vertex: "; 
                    std::cin >> v;
                    std::cout << "In-degree: " << g.get_in_degree(v) << "\n";
                    break;
                }
                case 12: {
                    int v; 
                    std::cout << "Vertex: "; 
                    std::cin >> v;
                    std::cout << "Out-degree: " << g.get_out_degree(v) << "\n";
                    break;
                }
                case 13: // Parse vertices
                    for (int i = 0; i < g.get_nr_vertices(); i++) 
                        std::cout << i << " ";
                    std::cout << "\n";
                    break;
                case 14: { // Parse outbound
                    int v; 
                    std::cout << "Vertex: "; 
                    std::cin >> v;
                    for (auto const& [target, edge] : g.parse_out(v))
                        std::cout << v << "->" << target << " (" << edge->cost << ")\n";
                    break;
                }
                case 15: { // Parse inbound
                    int v; 
                    std::cout << "Vertex: "; 
                    std::cin >> v;
                    for (auto const& [source, edge] : g.parse_in(v))
                        std::cout << source << "->" << v << " (" << edge->cost << ")\n";
                    break;
                }
                case 16: {
                    int u, v; 
                    std::cout << "Start End: "; 
                    std::cin >> u >> v;
                    if (g.is_edge(u,v)) 
                        std::cout << "Cost: " << g.get_edge_id(u,v)->cost << "\n";
                    break;
                }
                case 17: {
                    int u, v, c; 
                    std::cout << "Start End NewCost: "; 
                    std::cin >> u >> v >> c;
                    if (g.is_edge(u,v)) 
                        g.get_edge_id(u,v)->cost = c;
                    break;
                }
                case 18: {
                    Graph copy_g = g; // Deep copy
                    std::cout << "Graph copied successfully.\n";
                    break;
                }
                case 19: {
                    int s, t;
                    std::cout << "Start End: ";
                    std::cin >> s >> t;

                    std::vector<int> path = shortest_path(g, s, t);

                    if (path.empty()) {
                        std::cout << "No path exists from " << s << " to " << t << ".\n";
                    } 
                    else {
                        std::cout << "Lowest length path: ";
                        for (size_t i = 0; i < path.size(); i++) {
                            std::cout << path[i];
                            if (i + 1 < path.size())
                                std::cout << " -> ";
                        }
                        std::cout << "\nLength: " << path.size() - 1 << "\n";
                    }
                    break;
                }
                case 20: {
                    SCCResult sccs = find_sccs(g);
                    std::cout << "Found " << sccs.size() << " Strongly Connected Components:\n";
                    for (size_t i = 0; i < sccs.size(); i++) {
                        std::cout << "SCC " << i + 1 << ": ";
                        for (int v : sccs[i]) std::cout << v << " ";
                        std::cout << "\n";
                    }
                    break;
                }
                case 21: {
                    int s,t;
                    std::cout<<"Start End: ";
                    std::cin>>s>>t;
                    DijkstraResult res = backwards_dijkstra(g, s, t);
                    std::vector<int> path = lowest_cost_walk(res, s, t);
                    if (path.empty()) {
                        std::cout << "No path exists from " << s << " to " << t << ".\n";
                    }
                    else {
                        std::cout<<"Lowest cost walk: ";
                        for (size_t i=0; i<path.size(); i++) {
                            std::cout<<path[i];
                            if (i+1 < path.size()) // avoind printing extra arrow at the end
                                std::cout << " -> ";
                        }
                        std::cout<<"\nCost: "<< res.dist.at(s)<<"\n";
                    }
                    break;
                }
                case 22: {
                    int s, t;
                    std::cout << "Start vertex: ";
                    std::cin >> s;
                    std::cout << "End vertex: ";
                    std::cin >> t;

                    try {
                        long long result = count_distinct_walks_dag(g, s, t);
                        std::cout << "Number of distinct walks from " << s << " to " << t
                                  << " is " << result << "\n";
                    }
                    catch (const std::exception& e) {
                        std::cout << e.what() << "\n";
                    }
                    break;
                }
                case 23: {
                    int s,t;
                    std::cout << "Start vertex: ";
                    std::cin >> s;
                    std::cout << "End vertex: ";
                    std::cin >> t;

                    MinCostWalkCountResult ans = count_min_cost_walks(g, s, t);

                    if (!ans.path_exists) {
                        std::cout << "No path exists from " << s << " to " << t << ".\n";
                    }
                    else if (ans.infinite) {
                        std::cout << "Minimum cost: " << ans.min_cost << "\n";
                        std::cout << "There are infinitely many distinct minimum-cost walks.\n";
                    }
                    else {
                        std::cout << "Minimum cost: " << ans.min_cost << "\n";
                        std::cout << "Number of distinct minimum-cost walks: " << ans.count << "\n";
                    }
                    break;
                }
                case 24: {
                    try {
                        std::vector<int> topo = topological_sort(g);

                        if ((int)topo.size() != g.get_nr_vertices()) {
                            std::cout << "Graph is not a DAG.\n";
                            break;
                        }

                        std::cout << "Graph is a DAG.\n";

                        std::cout << "Topological order: ";
                        for (int x : topo) {
                            std::cout << x << " ";
                        }
                        std::cout << "\n";

                        int s, t;

                        std::cout << "Start vertex: ";
                        std::cin >> s;

                        std::cout << "End vertex: ";
                        std::cin >> t;

                        HighestCostPathResult result =
                            highest_cost_path_dag(g, s, t);

                        if (!result.path_exists) {
                            std::cout << "No path exists.\n";
                        }
                        else {
                            std::cout << "Highest cost: " << result.cost << "\n";

                            std::cout << "Path: ";

                            for (size_t i = 0; i < result.path.size(); i++) {
                                std::cout << result.path[i];

                                if (i + 1 < result.path.size()) {
                                    std::cout << " -> ";
                                }
                            }

                            std::cout << "\n";
                        }
                    }
                    catch (const std::exception& e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                }
                case 25: {
                    int s, t;
                    std::cout << "Start vertex: ";
                    std::cin >> s;
                    std::cout << "End vertex: ";
                    std::cin >> t;
                    try {
                        long long result = count_distinct_paths(g, s, t);
                        std::cout<<"Number of distinct paths: "<<result<<"\n";
                    }
                    catch (const std::exception& e) {
                        std::cout << "Error: "<<e.what() << '\n';
                    }
                    break;
                }
                case 26: {
                    int s, t;
                    std::cout << "Start vertex: ";
                    std::cin >> s;
                    std::cout << "End vertex: ";
                    std::cin >> t;
                    try {
                        std::pair<int, long long> result = count_lowest_cost_paths(g, s, t);

                        if (result.second == 0) {
                            std::cout << "No path exists.\n";
                        } else {
                            std::cout << "Lowest cost: " << result.first << "\n";
                            std::cout << "Number of distinct lowest cost paths: " << result.second << "\n";
                        }
                    }
                    catch (const std::exception& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}


/* graph1.txt: start: 0, target: 4
 * graph1k.txt: start: 0, target: 90
 * graph10k.txt: start: 0, target: 1549
 * graph100k.txt: start: 0, target: 39074
 */
