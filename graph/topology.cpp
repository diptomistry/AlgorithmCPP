#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int> >& adjList, int node, vector<bool>& visited, stack<int>& st) {//Using the & symbol to pass the stack by reference ensures that you are working with the same stack instance throughout the DFS traversal
    visited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited, st);
        }
    }

    st.push(node); // Push the current node to the stack after all its neighbors have been visited
}


vector<int> topologicalSort(vector<vector<int> >& adjList) {
    int N = adjList.size();
    vector<int> result;
    vector<bool> visited(N, false);
    stack<int> st;
     // Start DFS from a particular node:(we can ignore it if we want to start from 0)
    if (!visited[1]) {
        dfs(adjList, 1, visited, st);
    }
    // Then, go over the rest of the nodes
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(adjList, i, visited, st);
        }
    }

    // Extract the topological order from the stack
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main() {
    
    int numNodes = 8;
    vector<vector<int> > adjList(numNodes);

   
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[3].push_back(4);
    adjList[3].push_back(2);
    adjList[0].push_back(3);
    adjList[7].push_back(5);
    adjList[6].push_back(3);
    adjList[6].push_back(5);
    adjList[5].push_back(4);

    vector<int> sortedOrder = topologicalSort(adjList);

    cout << "Topological Sort Order: ";
    for (int i = 0; i < sortedOrder.size(); i++) {
        cout << sortedOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
