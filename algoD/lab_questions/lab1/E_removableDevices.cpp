#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000; 

vector<int> graph[MAX_N];
int indegree[MAX_N];
bool visited[MAX_N];

int countRemovableDevices(int n) {
    int removableDevices = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[i].size() == 1) {
            removableDevices++;
            visited[i] = true;
            int node = i;
            while (!visited[graph[node][0]]) {
                node = graph[node][0];
                visited[node] = true;
            }
        }
    }

    return removableDevices;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
        indegree[v]++;
    }

    int removableDevices = countRemovableDevices(n);

    cout  << removableDevices << endl;

    return 0;
}