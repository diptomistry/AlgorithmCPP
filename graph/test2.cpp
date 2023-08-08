#include <bits/stdc++.h>
using namespace std;
#define pb push_back

unordered_map<int, vector<int> > adj;

void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int> >& bridge, int V) {
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (disc[v] == -1) {
            parent[v] = u;
            DFS(v, disc, low, parent, bridge, V);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                bridge.pb(make_pair(u, v));
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges_Tarjan(int V) {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<pair<int, int> > bridge;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1)
            DFS(i, disc, low, parent, bridge, V);
    }

    cout << "Bridges are: \n";
    for (int i = 0; i < bridge.size(); ++i) {
        cout << bridge[i].first << "-->" << bridge[i].second << "\n";
    }
}

int main() {
    int V, m;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    findBridges_Tarjan(V);
    return 0;
}
