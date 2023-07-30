#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited = {0};
vector<int> tim[100];

int component = 0;
int l = 0;
void add_edge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int node)
{
    l += 1;
    visited[node] = true;
    
    vector<int> adj = graph[node];
    sort(adj.begin(), adj.end());
    tim[node].push_back(component);
    tim[node].push_back(l);
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[adj[i]] == false)
        {

            dfs(adj[i]);
            
        }
    }

    l++;
    tim[node].push_back(l);

    
}
int p = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        graph[i].clear();
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            component++;
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < tim[i].size(); j++)
        {
            cout << tim[i][j] << " ";
        }
        cout << endl;
    }
}