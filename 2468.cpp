#include <bits/stdc++.h>
using namespace std;

int N, maxH = 0;
vector<vector<int>> adj;
vector<int> ans;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void bfs(vector<vector<int>>& v, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        if (v[y][x]) continue;
        v[y][x] = 1;
        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            if (v[ny][nx]) continue;
            if (v[ny][nx] == 0) {
                q.push({ny, nx});
            }
        }
    }    
}

void solve() {
    for (int h = 0; h <= maxH; ++h) {
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (adj[i][j] <= h) {
                    v[i][j] = 1; // 1 is unsafe
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (v[i][j]) continue;
                bfs(v, i, j);
                ans[h]++;
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end());
}

int main() {
    cin >> N;
    adj.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] > maxH) {
                maxH = adj[i][j];
            }
        }
    }
    ans.resize(maxH + 1);
    solve();
    return 0;
}