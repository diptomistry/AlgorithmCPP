#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100; 
const int MAX_M = 100;

int N, M;
char grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '.' && !visited[x][y]);
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

      
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int countConnectedAreas() {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                count++;
            }
        }
    }

    return count;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int connectedAreas = countConnectedAreas();
    cout << connectedAreas << endl;

    return 0;
}