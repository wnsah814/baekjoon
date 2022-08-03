#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#include <utility>
using namespace std;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N;
int adj[101][101];
bool visited[101][101];

void bfs(int i, int j, int h) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        if (adj[y][x] <= h || visited[y][x]) continue;
        visited[y][x] = true;
        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            if (visited[ny][nx] || adj[ny][nx] <= h) continue;
            q.push({ny, nx});
        }
    }    
}
// void dfs(int y, int x, int h) {
//     visited[y][x] = true;
//     for (int k = 0; k < 4; ++k) {
//         int ny = y + dy[k];
//         int nx = x + dx[k];
//         if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
//         if (visited[ny][nx] || adj[ny][nx] <= h) continue;
//         dfs(ny, nx, h);
//     }
// }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int maxH = 0, minH = 101;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> adj[i][j];
                maxH = max(adj[i][j], maxH);
                minH = min(adj[i][j], minH);
            }
        }

        int maxD = 1;
        for (int h = minH; h <= maxH; ++h) {
            memset(visited, false, sizeof(visited));
            int tmp = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (adj[i][j] > h && !visited[i][j]) {
                        bfs(i, j, h);
                        // dfs(i, j, h);
                        tmp++;
                    }
                }
            }
            maxD = max(maxD, tmp);
        }
        cout << "#" << t << ' ' << maxD << '\n';
    }
    return 0;
}