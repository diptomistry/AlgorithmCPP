#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

void bfs(vector<vector<int>>& adjList, vector<int>& shortestPath) {
    int N = adjList.size();
    queue<int> q;
    vector<bool> visited(N, false);

    q.push(0); 
    visited[0] = true;
    shortestPath[0] = 0;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (int nextNode : adjList[currNode]) {
            if (!visited[nextNode]) {
                q.push(nextNode);
                visited[nextNode] = true;
                shortestPath[nextNode] = shortestPath[currNode] + 1;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N);
    vector<int> shortestPath(N, INF);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
    }

    bfs(adjList, shortestPath);

    for (int i = 0; i < N; i++) {
        if (shortestPath[i] != INF) {
            cout << i << ": " << shortestPath[i] << endl;
        } else {
            cout << i << ": Not Reachable" << endl;
        }
    }

    return 0;
}