#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m;
vector<int> adj[N];
int dfn[N], low[N], parent[N], timeStamp;
stack<int> S;
vector<vector<int> > components;
vector<pair<int, int> > bridges; // Array to store bridges

void dfs(int u) {
  dfn[u] = low[u] = ++timeStamp;
  S.push(u);

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (dfn[v] == 0) {
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        bridges.push_back(make_pair(u, v)); // Store the bridge
      }
      if (low[v] >= dfn[u]) {// (low[v] == dfn[u]), it means that vertex v is an ancestor of vertex u in the DFS tree.so it should be in the same bcc
        vector<int> component;//store the vertices of a biconnected component.
        int w;
        do {
          w = S.top();
          S.pop();
          component.push_back(w);
        } while (w != v);//This loop essentially removes vertices from the stack until the traversal reaches the vertex v (which is the endpoint of the component).
        component.push_back(u);
        components.push_back(component);//store all the bcc
        //ensures that all vertices within the same biconnected component are correctly grouped together.
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  cin >> n >> m;//vertices and edges
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (dfn[i] == 0) {
      dfs(i);
    }
  }

  cout << "Bridges are:" << endl;
  for (int i = 0; i < bridges.size(); i++) {
    cout << bridges[i].first << "-->" << bridges[i].second << endl;
  }

  cout << "Biconnected Components are:" << endl;
  for (int i = 0; i < components.size(); i++) {
    for (int j = 0; j < components[i].size(); j++) {
      cout << components[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
