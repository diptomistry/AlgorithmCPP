#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numVertices = 4; // Number of vertices in the graph

    // Create an adjacency list with 4 empty vectors representing 4 vertices
    vector<vector<int> > adjList(numVertices);

    // Add edges to the graph (0-based indexing)
    adjList[0].push_back(1);
    adjList[1].push_back(0);// Edge between vertex 0 and vertex 1(undirected)
    adjList[0].push_back(2); // Edge between vertex 0 and vertex 2
    adjList[1].push_back(3); // Edge between vertex 1 and vertex 3

    // Print the adjacency list
    for (int u = 0; u < numVertices; u++) {
        cout << "Neighbors of vertex " << u << ": ";
        for (int v : adjList[u]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}