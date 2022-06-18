#include <bits/stdc++.h>
using namespace std;
vector<int> sex;
vector<int> p;
vector<tuple<int, int, int>> edges;

int Find(int val) {
    if (p[val] == val) return val;
    return p[val] = Find(p[val]);
}

int Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return 0;
    p[a] = b;
    return 1;
}

void solve() {
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int w, u, v;
        tie(w, u, v) = edges[i];
        if (sex[u] == sex[v]) continue;
        if (Union(u, v)) {
            ans += w;
        }
    }
    int a = Find(0);
    for (int i = 1; i < p.size(); ++i) {
        if (a != Find(i)) {
            cout << "-1";
            return;
        }
    }
    cout << ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        p.push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (c == 'M') {
            sex.push_back(0);
        } else {
            sex.push_back(1);
        }
    }
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, u, v});
    }
    solve();
    return 0;   
}