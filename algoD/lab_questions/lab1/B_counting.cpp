#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 20; 
vector<int> graph[MAX_N];
int indegree[MAX_N];
int n, m;

int countTopologicalOrders(int node, vector<bool>& visited) {
    if (node == n) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && indegree[i] == 0) {//indegree 0 nodes have no incoming edges and can be included in the topological order as the first nodes.
            visited[i] = true;
            for (int v : graph[i]) {
                indegree[v]--;
            }
            count += countTopologicalOrders(node + 1, visited);
            visited[i] = false;
            for (int v : graph[i]) {
                indegree[v]++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<bool> visited(n, false);
    int numTopologicalOrders = countTopologicalOrders(0, visited);

    cout << numTopologicalOrders << endl;

    return 0;
}//For a node to be included in a valid 
//topological order, all of its incoming edges must come from nodes that are already included in the order.