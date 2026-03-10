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



