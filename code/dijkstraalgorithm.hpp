/*********************************************************************************
** MIT License
**
** Copyright (c) 2025 Vikas Awadhiya
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:

** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.

** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*********************************************************************************/

#ifndef  DIJKSTRA_ALGORITHM
#define  DIJKSTRA_ALGORITHM

#include <vector>

namespace dijkstraAlgorithm {

	/// @brief Implements Dijkstra’s shortest path algorithms.
	/// 
	/// @param source It represents starting vertex from where algorithm finds shortest path to each vertex.
	/// 
	/// @param graph It represents a graph (directed/undirected) in adjacency list format.
	/// 
	/// In two-dimension std::vector, the first dimension std::vector represent the vertices and it has one entry for 
	/// each vertex of a graph. Vertices are labelled from zero up-to one less than number of vertices in a graph.
	/// 
	/// Each vertex must be represented by an entry and in a directed graph if a vertex doesn’t have any outgoing edge 
	/// then it is required to be represented by an empty std::vector< std::pair< std::size_t, std::size_t > > and can’t 
	/// be avoided.
	/// 
	/// The second dimension std::vector is of std::vector< std::pair< std::size_t, std::size_t > > and represents edges
	/// of a vertex or out-going edges of a vertex in a directed graph. First element of the 
	/// std::pair<std::size_t, std::size_t> represent a vertex and the second element represent weight of an edge.
	///
	/// @return It returns std::pair of std::vector<std::size_t>
	/// 
	/// The first std::vector<std::size_t> of std::pair represents predecessor information and has one entry for each 
	/// vertex. The source vertex doesn’t have predecessor similarly a non-reachable vertex from source vertex also 
	/// doesn’t have predecessor and the vertex own value is set in its predecessor entry to represents threre is no 
	/// predecessor.
	/// 
	/// The second std::vector<std::size_t> of std::pair represents the shortest distance from the source vertex and has
	/// one entry for each vertex. The source vertex has zero value because it is starting vertex and a non-reachable 
	/// vertex has std::numeric_limits<size_t>::max() value that represents Infinity.
	/// 
	std::pair< std::vector<std::size_t>, std::vector<std::size_t> >
	shortestPath(std::size_t source, const std::vector< std::vector< std::pair<std::size_t, std::size_t> > >& graph);

}

#endif // ! DIJKSTRA_ALGORITHM


