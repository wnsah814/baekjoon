#include <stdio.h>
#include <string.h>

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N;
int adj[101][101];
int visited[101][101];

void dfs(int y, int x, int h) {
    visited[y][x] = 1;
    for (int k = 0; k < 4; ++k) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
        if (visited[ny][nx] || adj[ny][nx] <= h) continue;
        dfs(ny, nx, h);
    }
}

int main() {
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int maxH = 0, minH = 101;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &adj[i][j]);
                if (maxH < adj[i][j]) {
                    maxH = adj[i][j];
                }
                if (minH > adj[i][j]) {
                    minH = adj[i][j];
                }
            }
        }

        int maxD = 1;
        for (int h = minH; h < maxH; ++h) {
            memset(visited, 0, sizeof(visited));
            int tmp = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (adj[i][j] > h && !visited[i][j]) {
                        // bfs(i, j, h);
                        dfs(i, j, h);
                        tmp++;
                    }
                }
            }
            if (maxD < tmp) {
                maxD = tmp;
            }
        }
        printf("#%d %d\n", t, maxD);
    }
    return 0;
}