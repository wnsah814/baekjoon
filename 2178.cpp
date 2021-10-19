#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
const int MAX = 100;
int map[MAX][MAX] = { 0 };
bool visited[MAX][MAX];
int cnt[MAX][MAX] = { 0 };
int dx[] = {0,1,0,-1}; //CounterClockWise
int dy[] = {-1,0,1,0};

void bfs(int x, int y) {
    visited[x][y] = true;
    cnt[x][y]++;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt[nx][ny] = cnt[xx][yy] + 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0, 0);

    cout << cnt[N-1][M-1];
    return 0;
}