#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

bool hasCycle(int node, int parent) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, node))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycleInGraph(int N) {
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1))
                return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    adjList.resize(N);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
        adjList[V].push_back(U); 
    }

    if (hasCycleInGraph(N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}