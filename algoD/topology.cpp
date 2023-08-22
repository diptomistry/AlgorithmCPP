#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int> >& adjList, int node, vector<bool>& visited, stack<int>& st, vector<bool>& recursionStack) {//Using the & symbol to pass the stack by reference ensures that you are working with the same stack instance throughout the DFS traversal
    visited[node] = true;
    recursionStack[node] = true;
    //If a node is reached that is already in the recursion stack, then there is a cycle in the graph.
    for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];
        /*
        If the neighbor node has not been visited (!visited[neighbor]) and calling the DFS function recursively on that
         neighbor node (dfs(adjList, neighbor, visited, st, recursionStack)) returns true, it means that a cycle was detected 
         in the neighbor's subtree. */
         if (!visited[neighbor]) {
            if (dfs(adjList, neighbor, visited, st, recursionStack))
               { cout<<'a'<<neighbor<<endl;return true;}
        }
        /*
        If the neighbor node is already in the recursion stack (recursionStack[neighbor]), 
        it means that we've encountered a back edge, which indicates a cycle in the graph.
        */
        else if (recursionStack[neighbor])//the neighbor is already visited and in the recursionStack
            {cout<<'b'<<neighbor;
            return true;}
        
    }

    st.push(node);
    recursionStack[node] = false;
    return false;
}

vector<int> topologicalSort(vector<vector<int> >& adjList) {
    int N = adjList.size();
    vector<int> result;
    vector<bool> visited(N, false);
    vector<bool> recursionStack(N, false);
    stack<int> st;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            if (dfs(adjList, i, visited, st, recursionStack)) {
                cout << "Graph contains cycle" << endl;
                return vector<int>(); // return empty vector if graph has cycle//or simply return 0

            }
        }
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main() {
    
    int numNodes = 4;//8
    vector<vector<int> > adjList(numNodes);
    /*
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[3].push_back(4);
    adjList[3].push_back(2);
    adjList[0].push_back(3);
    adjList[7].push_back(5);
    adjList[6].push_back(3);
    adjList[6].push_back(5);
    adjList[5].push_back(4);
    */
    //cycle:
   
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
   
    

    vector<int> sortedOrder = topologicalSort(adjList);

    if(!sortedOrder.empty()){
        cout << "Topological Sort Order: ";
        for (int i = 0; i < sortedOrder.size(); i++) {
            cout << sortedOrder[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
//explanation:
/*
Starting DFS: 0 -> 1
DFS at node 1: 1 -> 2
DFS at node 2:2 -> 3
DFS at node 3:From node 3, DFS goes to node 1 (since 1 is the neighbor of 3). However, node 1 is already visited and it is in the recursion stack, so it goes into the second if clause, prints b1, and immediately returns true to indicate a cycle has been found.

The value true is returned back to the previous recursive call (DFS at node 3), and it prints a3. Since a cycle was found, there is no need to continue exploring other nodes from 3, and the recursive call returns true again.

The value true is returned back to the previous recursive call (DFS at node 2), and it prints a2. Similarly, there is no need to continue exploring other nodes from 2, and the recursive call returns true again.

The value true is returned back to the initial recursive call (DFS at node 1), and it prints a1. Again, there is no need to continue exploring other nodes from 1, and the recursive call returns true again.

The value true is returned back to the topologicalSort function from the initial recursive call (DFS at node 0). At this point, the topologicalSort function detects that a cycle is present and prints Graph contains cycle.

The program terminates since the graph contains a cycle and no further topological sorting is possible.

*/
