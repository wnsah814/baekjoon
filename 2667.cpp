#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> adj;
vector<vector<int>> visited;
vector<int> ans;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void bfs(int i, int j) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        if (visited[y][x]) continue;
        visited[y][x] = 1;
        cnt++;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            if (visited[ny][nx]) continue;
            if (adj[ny][nx] == 1) {
                q.push({ny, nx});
            }
        }
    }
    ans.push_back(cnt);
}

void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && adj[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int n : ans) {
        cout << n << '\n';
    }
}

int main() {
    cin >> N;
    adj.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            adj[i][j] = s[j] - '0';
        }
    }
    solve();
    return 0;
}