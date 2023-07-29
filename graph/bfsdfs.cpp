#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int> > adjList;
    vector<vector<int> > adjMatrix;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(n);//there will be n vectors and the vectors can be of different size
        adjMatrix.resize(n, vector<int>(n, 0));//this line of code initializes the adjMatrix with n rows and n columns, with all elements set to 0.
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);//v is considered a neighbor of vertex u
        adjList[v].push_back(u); // This ensures that the edge is undirected, meaning v is also considered a neighbor of vertex u, and there is an edge connecting them.
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    // BFS Traversal
    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (size_t i = 0; i < adjList[currentVertex].size(); i++) {
                int neighbor = adjList[currentVertex][i];
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    // DFS Traversal
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;

                for (size_t i = 0; i < adjList[currentVertex].size(); i++) {
                    int neighbor = adjList[currentVertex][i];
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
    }

    // Display adjacency matrix
    void displayAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int numVertices, numEdges;
   // cout << "Enter the number of vertices: ";
    cin >> numVertices;
   // cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g(numVertices);

    //cout << "Enter " << numEdges << " edges (u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
   // cout << "Enter the starting vertex for BFS and DFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    g.bfs(startVertex);
    cout << endl;

    cout << "DFS Traversal starting from vertex " << startVertex << ": ";
    g.dfs(startVertex);
    cout << endl;
    g.displayAdjMatrix();

    return 0;
}