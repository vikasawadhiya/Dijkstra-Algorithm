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

#include <queue>
#include <numeric>

#include <stdexcept>

using namespace std;

namespace dijkstraAlgorithm {

	pair< vector<size_t>, vector<size_t> >
	shortestPath(size_t source, const vector< vector< pair<size_t, size_t> > >& graph) {

		if ( source >= graph.size() ) { /// Vertices are labelled from 0 to graph.size() - 1.

			throw invalid_argument("Invalid source vertex.");
		}

		vector<bool> vertexSelectStatus( graph.size() );

		vector<size_t> vertexDistance( graph.size(), numeric_limits<size_t>::max() );

		vector<size_t> predecessorVertex( graph.size() );
		iota(predecessorVertex.begin() + 1, predecessorVertex.end(), 1); ///Set the vertex as its own predecessor.

		///Compares if the distance of first vertex is greater than the distance of second vertex.
		/// 
		auto greaterDistance =
			[](const pair<size_t, size_t>& vertex1Distance, const pair<size_t, size_t>& vertex2Distance) -> bool {

				return vertex2Distance.second < vertex1Distance.second;
			};

		vertexDistance[source] = 0;

		priority_queue< pair<size_t, size_t>, vector< pair<size_t, size_t> >, decltype(greaterDistance) >
			vertexQueue(greaterDistance);

		vertexQueue.emplace(source, 0);

		while ( !vertexQueue.empty() ) {

			if ( !vertexSelectStatus[vertexQueue.top().first] ){ /// Vertex select/discover status improve efficiency 
																 /// when it is used with edges of positive weights.

				size_t vertex = vertexQueue.top().first;
				vertexQueue.pop();

				vertexSelectStatus[vertex] = true;

				for (auto edgeIt = graph[vertex].cbegin(); graph[vertex].cend() != edgeIt; ++edgeIt) {

					if (!vertexSelectStatus[edgeIt->first] && 
						(numeric_limits<size_t>::max() == vertexDistance[edgeIt->first] ||
						vertexDistance[vertex] + edgeIt->second < vertexDistance[edgeIt->first]) ) {

						vertexDistance[edgeIt->first] = vertexDistance[vertex] + edgeIt->second;
						predecessorVertex[edgeIt->first] = vertex;

						vertexQueue.emplace(edgeIt->first, vertexDistance[edgeIt->first]);
					}
				}
			}
			else {
				vertexQueue.pop();
			}
		}

		return { std::move(predecessorVertex), std::move(vertexDistance) };
	}
}