#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100000; 

vector<int> graph[MAX_N];
bool visited[MAX_N];
stack<int> topologicalOrder;

void dfs(int node) {
    visited[node] = true;
    for (int v : graph[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    topologicalOrder.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

 
    while (!topologicalOrder.empty()) {
        cout << topologicalOrder.top() << endl;
        topologicalOrder.pop();
    }

    return 0;
}