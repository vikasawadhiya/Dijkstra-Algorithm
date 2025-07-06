# Dijkstra's Algorithm

<p align="justify">Dijkstra’s algorithm finds shortest path in a weighted graph from source vertex to all other 
vertices. It can be customized to find the shortest path from source vertex u to a specific 
destination vertex v. The algorithm doesn’t find shortest path directly rather it finds shortest 
distance and by backtracking the predecessor up to source vertex, a shortest path can be found.

The Dijkstra’s algorithm works with simple graph, multi-graph, connected graph, disconnected 
graph and all combination of these with undirected and directed weighted graphs for 
example directed/undirected simple graph, directed/undirected multi-graph. The only 
constraint is, a graph must not have any edges of negative weights. 

The time complexity of Dijkstra’s shortest path algorithm is O( (V + E) log V ) where a binary 
heap (priority queue) data structure is used to find a vertex at smallest distance among the undiscovered 
vertices. Here V is number of vertices |V|, and E is number of edges |E| in a graph.

Dijkstra’s algorithm belongs to a specific category of algorithms called greedy algorithms.

</p>


## Tutorial Document

<p align="justify">Tutorial document 
<a href="https://github.com/vikasawadhiya/Dijkstra-Algorithm/blob/main/Dijkstra’sAlgorithm.pdf">Dijkstra’sAlgorithm.pdf</a> 
explains Dijkstra’s shortest path algorithm in detail. 
The tutorial document first introduces Dijkstra’s algorithm then explains different types of graphs where 
Dijkstra’s algorithm works. It lists all four steps of algorithm and then considers an undirected 
simple weighted graph to explain these steps throughout as a complete example.

The tutorial document then discusses about the negative weight constraint and why Dijkstra’s algorithm 
doesn’t work with a graph has any edges of negative weights. Then it explains time and space complexities of 
Dijkstra’s algorithm with the help of a complete graph.

The tutorial document uses a lot of pictorial representation.
</p>

## Usage

<p align="justify">Implementation can be used to find shortest path from a given source vertex 
to all other vertices of a graph by passing the source vertex and a graph to <code>dijkstraAlgorihtm::shortestPath</code> function.

#### Graph Initialization

It is a simple directed weighted graph with three vertices and it can be considered as a triangle where 
three corners of the triangle represent three vertices. The left side of the triangle has one vertex and it is labelled 
as vertex 0 and the opposite side of it there are two vertices labelled 1 and 2 in clockwise direction respectively.
</p>

```cpp
std::vector< std::vector< std::pair<std::size_t, std::size_t> > >  graph { { {1, 1}, {2, 3} }, { {2, 1} }, {  } };
```
<p align="justify">
Here an edge is represented by a <code>std::pair&lt;std::size_t, std::size_t&gt;</code> where first <code>std::size_t</code> represents vertex 
and second <code>std::size_t</code> represents weight of the edge. The <code>std::size_t</code> data type ruled out any possibility of a negative weight.

Last entry in the graph is an empty <code>std::vector< pair<std::size_t, std::size_t> ></code> because vertex 2 doesn’t have any outgoing edge but 
it is required to represente by empty entry and can’t be ignored.
</p>

#### Function Invocation

```cpp
std::pair< std::vector<std::size_t>, std::vector<std::size_t> > predDistance = dijkstraAlgorihtm::shortestPath(0, graph);
```

<p align="justify">
It returns <code>std::pair&lt; std::vector&lt;std::size_t&gt;, std::vector&lt;size_t::size_t&gt; &gt;</code>, where first 
<code>std::vector&lt;std::size_t&gt;</code> represents predecessor information of all vertices and the second <code>std::vector&lt;std::size_t&gt;</code> 
represents shortest distance information of all vertices.
<p align="justify">

## Example

<p align="justify">A simple undirected weighted graph as shown in Fig A below on the left with vertex u as source 
vertex and the shortest path to each vertex from source vertex u is highlighted by bold lines and shown in Fig B below on the right.
</p>

<p align="center">
<img src="https://github.com/vikasawadhiya/Dijkstra-Algorithm/blob/main/shortestPath.png" alt="Shortest path of each vertex.">
</p>

## License

The code is licenced under the [MIT License](https://github.com/vikasawadhiya/Dijkstra-Algorithm/blob/main/LICENSE).</br>
The tutorial document [Dijkstra’sAlgorithm.pdf](https://github.com/vikasawadhiya/Dijkstra-Algorithm/blob/main/Dijkstra’sAlgorithm.pdf) and 
[shortestPath.png](https://github.com/vikasawadhiya/Dijkstra-Algorithm/blob/main/shortestPath.png) 
are licensed under the [CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/).