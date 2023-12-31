#include<bits/stdc++.h>

using namespace std;




// Define a structure to represent an edge between two towers.
struct Edge {
    int tower1, tower2, length;
    
    Edge(int t1, int t2, int len) : tower1(t1), tower2(t2), length(len) {}
    
    // Overload the less-than operator for sorting edges by length.
    bool operator<(const Edge& other) const {
        return length < other.length;
    }
};




// Function to find the parent of a node in the disjoint-set data structure.
int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return findParent(parent, parent[node]);
}



// Function to perform union of two sets in the disjoint-set data structure.
void unionSets(vector<int>& parent, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rootU != rootV)
        parent[rootU] = rootV;
}



// Kruskal's algorithm to find the Minimum Spanning Tree.
vector<Edge> kruskalMST(vector<Edge>& edges, int numTowers) {
    vector<Edge> mst;
    
    // Sort the edges by length in non-decreasing order.
    sort(edges.begin(), edges.end());
    
    // Initialize a parent array for the disjoint-set data structure.
    vector<int> parent(numTowers);
    for (int i = 0; i < numTowers; i++)
        parent[i] = i;
    
    // Iterate through sorted edges and add them to the MST if they do not create a cycle.
    for (const Edge& edge : edges) {
        int root1 = findParent(parent, edge.tower1);
        int root2 = findParent(parent, edge.tower2);
        
        if (root1 != root2) {
            mst.push_back(edge);
            unionSets(parent, root1, root2);
        }
    }
    
    return mst;
}



int main() {
    int numTowers = 7; // Number of cell towers
    vector<Edge> edges; // Edges representing cable lengths
    
    // Define edges (tower1, tower2, length) in the grid-based city.
    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(1, 2, 4));
    edges.push_back(Edge(1, 3, 5));
    edges.push_back(Edge(2, 3, 7));
    edges.push_back(Edge(2, 4, 9));
    edges.push_back(Edge(3, 4, 3));
    
    // Call Kruskal's algorithm to find the MST.
    vector<Edge> mst = kruskalMST(edges, numTowers);
    
    // Display the resulting MST edges.
    cout << "Minimum Spanning Tree Edges:\n";
    for (const Edge& edge : mst) {
        cout << "Tower " << edge.tower1 << " - Tower " << edge.tower2 << ", Cable Length: " << edge.length << endl;
    }
    
    return 0;
}
