#include <bits/stdc++.h>
using namespace std;

int SCC_count = 0; // Global variable to store the number of SCCs

void dfs(vector<vector<int> >& adjList, int node, vector<bool>& visited, stack<int>& st, vector<bool>& recursionStack, vector<int>& disc, vector<int>& low) {
    static int time = 0;
    visited[node] = true;
    disc[node] = low[node] = ++time;
    st.push(node);
    recursionStack[node] = true;

    for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];

        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited, st, recursionStack, disc, low);
            low[node] = min(low[node], low[neighbor]);
        } else if (recursionStack[neighbor]) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }

    if (low[node] == disc[node]) {
        SCC_count++; // Increment SCC count
        cout << "Strongly Connected Component " << SCC_count << ": ";
        while (true) {
            int v = st.top();
            st.pop();
            recursionStack[v] = false;
            cout << v << " ";
            if (v == node) break;
        }
        cout << endl;
    }
}

vector<int> topologicalSort(vector<vector<int> >& adjList) {
    int N = adjList.size();
    vector<int> result;
    vector<bool> visited(N, false);
    vector<bool> recursionStack(N, false);
    vector<int> disc(N, -1);
    vector<int> low(N, -1);
    stack<int> st;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(adjList, i, visited, st, recursionStack, disc, low);
        }
    }

    return result;
}

int main() {
    int numNodes = 5;
    vector<vector<int> > adjList(numNodes);

   adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(2);

    vector<int> sortedOrder = topologicalSort(adjList);

    cout << "Number of Strongly Connected Components: " << SCC_count << endl;

    return 0;
}
