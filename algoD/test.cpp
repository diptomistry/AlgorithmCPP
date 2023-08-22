#include <bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int, vector<int> > adj;

void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int> >& bridge, vector<vector<int> >& bcc) {
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (disc[v] == -1) { // If v is not visited
            parent[v] = u;
            DFS(v, disc, low, parent, bridge, bcc);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) // no back edge
                bridge.pb(make_pair(u, v));

        } else if (v != parent[u] && disc[v] < disc[u]) { // already visited and not parent meaning back edge
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBiconnectedComponents_Tarjan() {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<pair<int, int> > bridge;
    vector<vector<int> > bcc;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1)
            DFS(i, disc, low, parent, bridge, bcc);
    }

    cout << "Bridges are:\n";
    for (int i = 0; i < bridge.size(); ++i) {
        cout << bridge[i].first << "-->" << bridge[i].second << "\n";
    }

    cout << "\nBiconnected Components are:\n";
    for (int i = 0; i < bcc.size(); ++i) {
        for (int j = 0; j < bcc[i].size(); ++j) {
            cout << bcc[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
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

    findBiconnectedComponents_Tarjan();
    return 0;
}

/*
int main() {
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
   /*
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

    findBridges_Tarjan();
    findBiconnectedComponents_Tarjan(); 
    return 0;
}



//TIME COMPLEXITY: O(V+E)
/*
//back edge can never be a bridge
https://youtu.be/Rhxs4k6DyMM
 we dont  consider child-parent edge as it is not a backedge:https://youtu.be/Rhxs4k6DyMM?t=510
*/