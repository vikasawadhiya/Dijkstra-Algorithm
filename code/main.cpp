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

#include "dijkstraalgorithm.hpp"

#include <iostream>

#include <tuple>
#include <vector>

#include <queue>

using namespace std;

/// @brief Print the shortest path as a sequence of vertices from the source to destination vertex.
/// @param v It represents destination vertex.
/// @param predecessor It represents predecessor vertex information of each vertex.
/// @param distance It represents shortest distance of each vertex from source vertex.
/// 
void printShortestPath(size_t v, const vector<size_t>& predecessor, const vector<size_t>& distance) {

	if ( v >= predecessor.size() ) {

		cout << "Invalid destination vertex " << v << '.';
		return;
	}
	
	size_t destinationVertex = v;

	vector<size_t> path{ v };

	while (predecessor[v] != v) {

		path.push_back(predecessor[v]);
		v = predecessor[v];
	}

	cout << "v = " << destinationVertex << ", Distance = ";

	if (std::numeric_limits<size_t>::max() == distance[destinationVertex]) {

		cout << "Infinity";
	}
	else {
		cout << distance[destinationVertex] << ", Path = " << path.back();

		for (auto rIt = path.crbegin() + 1; path.crend() != rIt; ++rIt) {

			cout << ", " << *rIt;
		}
	}

}

int main(int, char*[]) {
	
	/// It is a simple directed weighted graph with three vertices and it can be considered as a triangle where 
	/// three corners of the triangle represent three vertices.
	/// 
	/// The left side of the triangle has one vertex and it is labelled as vertex 0 and the opposite side of it there 
	/// are two vertices labelled 1 and 2 in clockwise direction respectively.
	/// 
	vector< vector< pair<size_t, size_t> > > graph;
	graph.reserve(3);

	/// Vertex 0 has an outgoing edge of unit weight to vertex 1 and an outgoing edge of weight three to vertex 2.
	graph.emplace_back(vector< pair<size_t, size_t> >{ {1, 1}, { 2, 3} });

	/// Vertex 1 has an outgoing edge of unit weight to vertex 2.
	graph.emplace_back(vector< pair<size_t, size_t> >{ {2, 1} });

	/// Vertex 2 doesn’t have any outgoing edge but it is required to be represented by an empty entry.
	graph.push_back(vector< pair<size_t, size_t> >{});

	vector<size_t> predecessor;
	vector<size_t> distance;

	std::tie(predecessor, distance) = dijkstraAlgorithm::shortestPath(0, graph);

	printShortestPath(2, predecessor, distance);
	cout << endl;
	
}


