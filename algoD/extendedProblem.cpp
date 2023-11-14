#include<bits/stdc++.h>





using namespace std;

// Define a structure to represent an edge between two regions.
struct Edge {
    int region1, region2, latency;
    
    Edge(int r1, int r2, int lat) : region1(r1), region2(r2), latency(lat) {}
    
    // Overload the less-than operator for sorting edges by latency.
    bool operator<(const Edge& other) const {
        return latency < other.latency;
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
vector<Edge> kruskalMST(vector<Edge>& edges, int numRegions) {
    vector<Edge> mst;
    
    // Sort the edges by latency in non-decreasing order.
    sort(edges.begin(), edges.end());
    
    // Initialize a parent array for the disjoint-set data structure.
    vector<int> parent(numRegions);
    for (int i = 0; i < numRegions; i++)
        parent[i] = i;
    
    // Iterate through sorted edges and add them to the MST if they do not create a cycle.
    for (const Edge& edge : edges) {
        int root1 = findParent(parent, edge.region1);
        int root2 = findParent(parent, edge.region2);
        
        if (root1 != root2) {
            mst.push_back(edge);
            unionSets(parent, root1, root2);
        }
    }
    
    return mst;
}

int main() {
    int numRegions = 5; // Number of regions
    vector<Edge> edges; // Edges representing latency
    
    // Define edges (region1, region2, latency) in the metropolitan area.
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 15));
    edges.push_back(Edge(1, 2, 20));
    edges.push_back(Edge(1, 3, 25));
    edges.push_back(Edge(2, 3, 30));
    edges.push_back(Edge(2, 4, 35));
    edges.push_back(Edge(3, 4, 40));
    
    // Call Kruskal's algorithm to find the MST.
    vector<Edge> mst = kruskalMST(edges, numRegions);
    
    // Display the resulting MST edges.
    cout << "Minimum Spanning Tree Edges:\n";
    for (const Edge& edge : mst) {
        cout << "Region " << edge.region1 << " - Region " << edge.region2 << ", Latency: " << edge.latency << endl;
    }
    
    return 0;
}
