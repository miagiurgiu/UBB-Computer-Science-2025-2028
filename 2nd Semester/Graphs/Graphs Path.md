## Lecture 1 - 24 feb 2026
https://www.cs.ubbcluj.ro/~rlupsa/edu/grafe/index.html - website


## Lab 1 - 24 feb 2026

1. graph 6 vertices + 10 edges
		implement diagram, dictionary, text file
2. graph 7 vertices + 20 edges
3. graph 6 vertices + 40 edges
4. graph 1k, 10k, 100k

graph.txt
5 6
0 1 5
1 1 -1
1 2 6
2 3 10
2 1 7
3 1 9

5 = nr of vertices
6 = nr of edges


## Lab 2
2 pdfs (2 documentations)

Implementation
```
class Graph:
def __init__(self, nr_of_vertices=0,nr_of_edges=0):
	# creates a graph with the given nr of vertices and edges
	self.__vertices = set()
	self.__outbounds = dict()
	self.__inbounds = dict()
	self.__cost=dict()
```



Assignment 1:

how to run c++ code in vs code:
```
g++ -std=c++17 main.cpp graph.cpp -o graph_manager
```

Assignment 3:

BONUSES:
2B: Write a program that, given a graph that has no cycles (a directed acyclic graph, DAG) and a pair of vertices, finds the number of distinct walks between the given vertices.

For a DAG, we first compute a topological ordering `sorted`. Then we define:
- `nr[x]` = number of distinct walks from `s` to `x`
Initialization:
- `nr[s] = 1`
- `nr[x] = 0` for all `x ≠ s`
Then, processing vertices in topological order:
- for every edge `(x,y)`, we update  
    `nr[y] = nr[y] + nr[x]`
At the end, `nr[t]` is the number of distinct walks from `s` to `t`.
Why topological order matters
Because if `(x,y)` is an edge, then `x` appears before `y` in the topological sorting, so when updating `nr[y]`, the value `nr[x]`is already final.


## Seminar 5 - 8 may 2026

1) find longest path in that graph (DAG)
- does the problem always have a solution?
- is the path unique? no, there are more - one of them is fine
- length = nr of edges along that walk
- single vertex => path of length 0
- finite nr of paths, finite nr of walks
- 2^n paths for len=2*n
- dynamic programming approach
- w[x] = length of the longest path ending in x
- solution for DAG
	- topological sorting 
		- input: graph
		- output:
		- not unique solution
```
def toposort(g):
	''' performs the topological sorting of graph g,
	 returns the list of al vertices of g in a topological order
	 '''
	 
```