#include<bits/stdc++.h>
using namespace std;

// Depth-First Search for the original graph to compute finishing times

void dfs(vector<vector<int> >& adjList, int node, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited, st);
        }
    }
    st.push(node);//topological order is stored
}


// Transpose the graph (Reverse all edges)
//if the graph was=0:1,2
//T(graph)= 1:0,2:0
//adj[i][j]=adj[j][i]
vector<vector<int> > transposeGraph(const vector<vector<int> >& adjList) {
    int N = adjList.size();
    vector<vector<int> > transposed(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            int neighbor = adjList[i][j];
            transposed[neighbor].push_back(i);//j te i
        }
    }
    return transposed;
}


// Depth-First Search for the transposed graph to form SCCs
void dfsTranspose(vector<vector<int> >& adjList, int node, vector<bool>& visited, vector<int>& scc) {
    visited[node] = true;
    scc.push_back(node);
    for (int j = 0; j < adjList[node].size(); j++) {
        int neighbor = adjList[node][j];
        if (!visited[neighbor]) {
            dfsTranspose(adjList, neighbor, visited, scc);
        }
    }
}

// Find Strongly Connected Components in the graph
vector<vector<int> > findSCCs(vector<vector<int> >& adjList) {
    int N = adjList.size();
    vector<bool> visited(N, false);
    stack<int> st;

    // Step 1: Perform DFS to compute finishing times
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(adjList, i, visited, st);
        }
    }

    // Step 2: Transpose the graph
    vector<vector<int> > transposed = transposeGraph(adjList);

    // Step 3: Reset visited vector for the next DFS
    visited.assign(N, false);

    // Step 4: Perform DFS on the transposed graph in the order of decreasing finishing times
    /*
    The loop in Step 4 pops nodes from the stack obtained after the first DFS traversal (stored in st). For each popped node,
     if it has not been visited yet, a new SCC is initialized. Then, a new DFS traversal (dfsTranspose) is started from that 
     node on the transposed graph. This DFS will explore all nodes reachable from the current node in the transposed graph and
      add them to the same SCC.
    */
    vector<vector<int> > stronglyConnectedComponents;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> scc;
            dfsTranspose(transposed, node, visited, scc);
            stronglyConnectedComponents.push_back(scc);
        }
    }

    return stronglyConnectedComponents;
}

int main() {
    int numNodes = 8;
    vector<vector<int> > adjList(numNodes);

    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(0);
    adjList[4].push_back(5);

    adjList[5].push_back(6);
    adjList[6].push_back(4);
    adjList[6].push_back(7);

    vector<vector<int> > sccs = findSCCs(adjList);

    cout << "Strongly Connected Components:\n";
    for (int i = 0; i < sccs.size(); ++i) {
        cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < sccs[i].size(); ++j) {
            cout << sccs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
