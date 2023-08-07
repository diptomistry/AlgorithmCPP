#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > adjList(N);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
    }

    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j < adjList[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Input
6
6
1 2
1 3
0 1
2 4
4 5
5 1
Output
0: 1
1: 2 3
2: 4
3:
4: 5
5: 1
*/