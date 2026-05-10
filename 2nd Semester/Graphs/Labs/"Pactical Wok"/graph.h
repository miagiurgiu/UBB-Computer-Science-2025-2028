/*
Storage: adjacency list using std::vector of std::unordered map
Complexity:
    - add/remove edge: O(1) average case
    - Check edge: O(1) average case
    - Add vertex: O(1) amortized
    - Remove vertex: O(V+E) because of vector shifting and edge cleanup - ids may need to shift
Memory:
    - Rule of Three implemented (Destructor, Copy constructor, Assignment operator)
*/

#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>
#include <utility>


class Graph { // by default, the members of a class are private
public:
    struct Edge { // by default, the members of a struct are public
        int source; // starting vertex
        int target; // ending vertex
        int cost; 
    };

    typedef Edge* Edge_id; // Edge_id stores memory address of object Edge

private:
    int nr_vertices;
    int nr_edges;
    // Each index in the vector is a Vertex ID
    std::vector<std::unordered_map<int, Edge_id>> outbound; // dictionary where key=int, value=edge_id
    std::vector<std::unordered_map<int, Edge_id>> inbound;

public:
    explicit Graph(int n = 0); // default constructor -> creates graph with n vertices and 0 edges  
    Graph(const Graph& other); // Copy constructor
    Graph& operator=(const Graph& other); // Assignment operator
    ~Graph();                             // Destructor

    int get_nr_vertices() const;
    int get_nr_edges() const; // added
    void add_vertex();
    void remove_vertex(int v);

    bool is_edge(int u, int v) const;
    Edge_id get_edge_id(int u, int v) const;

    void add_edge(int u, int v, int cost);
    void remove_edge(int u, int v);

    int get_in_degree(int v) const;
    int get_out_degree(int v) const;

    // Requirement: "parse (iterate) the set of outbound/inbound edges"
    const std::unordered_map<int, Edge_id>& parse_out(int v) const;
    const std::unordered_map<int, Edge_id>& parse_in(int v) const;

};

struct BFSResult {
    std::unordered_map<int, int> distance;
    std::unordered_map<int, int> parent;
};

BFSResult bfs(const Graph& g, int s, int t = -1);
std::vector<int> shortest_path(const Graph& g, int s, int t);

Graph read_from_file(const std::string& filename);
void write_to_file(const Graph& g, const std::string& filename);
Graph create_random_graph(int n, int m);

// Add to the bottom of graph.h
typedef std::vector<std::vector<int>> SCCResult;

SCCResult find_sccs(const Graph& g);
void dfs_first_pass(int v, const Graph& g, std::unordered_set<int>& visited, std::vector<int>& stack);
void dfs_second_pass(int v, const Graph& g, std::unordered_set<int>& visited, std::vector<int>& current_scc);

struct DijkstraResult {
    std::unordered_map<int, int> dist;
    std::unordered_map<int, int> next;
};

DijkstraResult backwards_dijkstra(const Graph& g, int s, int t);
std::vector<int> lowest_cost_walk(const DijkstraResult& result, int s, int t);

// bonus 2b
// predecessor topological sort
std::vector<int> topological_sort(const Graph& g);
struct LongestPathResult {
    int length; // nr of edges
    std::vector<int> path; // one longest path
};
LongestPathResult longest_path_dag(const Graph& g);

// practical work 4
// dfs topological sort (tarjan)
std::vector<int> topological_sort_dfs(const Graph& g);
struct HighestCostPathResult {
    bool path_exists;
    long long cost;
    std::vector<int> path;
};
HighestCostPathResult highest_cost_path_dag(const Graph& g, int s, int t);


long long count_distinct_walks_dag(const Graph& g, int s, int t);

// bonus 1b
struct MinCostWalkCountResult {
    int min_cost;
    long long count;
    bool infinite;
    bool path_exists;
};

MinCostWalkCountResult count_min_cost_walks(const Graph& g, int s, int t);

std::pair<int, long long> count_lowest_cost_paths(const Graph& g, int s, int t);
long long count_distinct_paths(const Graph& g, int s, int t);
#endif