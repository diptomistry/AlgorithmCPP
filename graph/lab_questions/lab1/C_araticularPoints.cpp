#include<bits/stdc++.h>
#define MAXN 10000

using namespace std;

vector<int> adj[MAXN];
bool visited[MAXN];
int tin[MAXN];
int low[MAXN];
int timer;
set<int> AP; 
vector<pair<int, int> > bridge; 

void DFS(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0; 
    for (int i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (to == p) continue; 
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            DFS(to, v); 
            low[v] = min(low[v], low[to]); 
           
            if (low[to] >= tin[v] && p != -1)
                AP.insert(v);
            ++children; 
        }
        if (p == -1 && children > 1)
            AP.insert(v);
        
        if (low[to] > tin[v])
            bridge.push_back(make_pair(v, to)); 
    }
}

void findAP_Bridges(int n) {
    timer = 0; 
    AP.clear();
    bridge.clear(); 

    for (int i = 0; i < n; ++i) {
        visited[i] = false; 
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            DFS(i);
    }
}

int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findAP_Bridges(nodes);

    
   
    for (set<int>::iterator it = AP.begin(); it != AP.end(); ++it) {
        cout << *it <<endl;
    }
   



    return 0;
}