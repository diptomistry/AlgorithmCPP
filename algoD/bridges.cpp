#include <bits/stdc++.h>
using namespace std;
#define V 6
#define pb push_back

unordered_map<int, vector<int> > adj;

void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int> >& bridge) {
    static int time = 0;//this line will be initiallized only once then this line will be ignored
    disc[u] = low[u] = time;
    time += 1;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (disc[v] == -1) { // If v is not visited
            parent[v] = u;
            DFS(v, disc, low, parent, bridge);//dfs call to the child of u
            low[u] = min(low[u], low[v]);//after returning to u by recursion

            if (low[v] > disc[u])//no back edge
                bridge.pb(make_pair(u, v));

        } else if (v != parent[u]) { // already visited and not parent meaning backedge
            low[u] = min(low[u], disc[v]);//for backedge:https://youtu.be/ZeDNSeilf-Y?t=1161
        }
    }
}

void findBridges_Tarjan() {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<pair<int, int> > bridge;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1)
            DFS(i, disc, low, parent, bridge);
    }

    cout << "Bridges are: \n";
    for (int i = 0; i < bridge.size(); ++i) {
        cout << bridge[i].first << "-->" << bridge[i].second << "\n";
    }
}

int main() {
    adj[0].pb(3);
    adj[3].pb(0);
    adj[3].pb(2);
    adj[2].pb(3);
    adj[2].pb(1);
    adj[1].pb(2);
    adj[2].pb(4);
    adj[4].pb(2);
    adj[2].pb(5);
    adj[5].pb(2);
    adj[4].pb(5);
    adj[5].pb(4);
    adj[1].pb(4);
    adj[4].pb(1);
    /*
    adj[0].pb(2);
	adj[2].pb(0);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[1].pb(0);
	adj[0].pb(1);
	adj[2].pb(1);
	adj[1].pb(2);
	adj[3].pb(4);
	adj[4].pb(3);
    */

    findBridges_Tarjan();
    return 0;
}


//TIME COMPLEXITY: O(V+E)
/*
//back edge can never be a bridge
https://youtu.be/Rhxs4k6DyMM
 we dont  consider child-parent edge as it is not a backedge:https://youtu.be/Rhxs4k6DyMM?t=510
*/