#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int numV, numE;
vector<int> adj[N];
int dfn[N], low[N], parent[N], timeStamp;
stack<int> S;
vector<vector<int> > components;

void dfs(int u) {
  dfn[u] = low[u] = ++timeStamp;
  S.push(u);

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (dfn[v] == 0) {
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        vector<int> component;
        int w;
        do {
          w = S.top();
          S.pop();
          component.push_back(w);
        } while (w != v);
        component.push_back(u);
        components.push_back(component);
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  cin >> numV >> numE;
  for (int i = 0; i < numE; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= numV; i++) {
    if (dfn[i] == 0) {
      dfs(i);
    }
  }
  cout<<"bcc:"<<endl;
  for (int i = 0; i < components.size(); i++) {
    for (int j = 0; j < components[i].size(); j++) {
      cout << components[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
