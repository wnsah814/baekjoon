#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> visited;

void solve() {
    int cnt = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        cnt++;
        for (int i = 0; i < int(adj[u].size());++i) {
            int v = adj[u][i];
            q.push(v);
        }
    }    
    cout << cnt;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();

    return 0;
}