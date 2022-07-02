#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p;
vector<vector<int>> party;
vector<int> knows;

int Find(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    p[x] = y;
}

bool same(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return true;
    return false;
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 1; j < party[i].size(); ++j) {
            Union(party[i][0], party[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        bool go = true;

        for (int j = 0; j < party[i].size(); ++j) {
            if (!go) break;
            for (int k = 0; k < knows.size(); ++k) {
                if (same(party[i][j], knows[k])) {
                    go = false;
                    break;
                }
            }
        }
        if (go) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    cin >> N >> M;
    p.resize(N + 1);

    party.resize(M);

    int n;
    cin >> n;
    knows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> knows[i];
    }

    for (int i = 0; i < M; ++i) {
        int ps;
        cin >> ps;
        for (int j = 0; j < ps; ++j) {
            int x;
            cin >> x;
            party[i].push_back(x);
        }
    }

    solve();

    return 0;
}