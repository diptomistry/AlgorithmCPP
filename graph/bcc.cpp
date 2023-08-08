#include <bits/stdc++.h>
using namespace std;
#define pb push_back

unordered_map<int, vector<int> > adj;

void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int> >& bridge, stack<pair<int, int> >& st) {
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (disc[v] == -1) {
            parent[v] = u;
            st.push(make_pair(u, v));
            DFS(v, disc, low, parent, bridge, st);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) { 
                bridge.pb(make_pair(u, v));
            }

           
            if (low[v] >= disc[u]) {//no back edge
                vector<pair<int, int> > component;
                while (!st.empty() && st.top() != make_pair(u, v)) {
                    component.push_back(st.top());
                    st.pop();
                }
                component.push_back(st.top());
                st.pop();
                cout << "Biconnected Component:";
                for (int i = component.size() - 1; i >= 0; --i) {
                    cout << " " << component[i].first << "-" << component[i].second;
                }
                cout << endl;
            }
        } else if (v != parent[u] && disc[v] < disc[u]) {
            st.push(make_pair(u, v));
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridgesAndBCCs_Tarjan(int V) {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<pair<int, int> > bridge;
    stack<pair<int, int> > st;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1)
            DFS(i, disc, low, parent, bridge, st);
    }

    cout << "Bridges are: \n";
    for (int i = 0; i < bridge.size(); ++i) {
        cout << bridge[i].first << "-->" << bridge[i].second << "\n";
    }
}

int main() {
    int V, m;
    //cout << "Enter the number of vertices: ";
    cin >> V;
    //cout << "Enter the number of edges: ";
    cin >> m;
   // cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    findBridgesAndBCCs_Tarjan(V);
    return 0;
}
