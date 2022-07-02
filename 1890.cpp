#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> v;
vector<vector<ll>> dp;

void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int move = v[i][j];
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

            if (i + move < N) dp[i + move][j] = dp[i + move][j] + dp[i][j];
            if (j + move < N) dp[i][j + move] = dp[i][j + move] + dp[i][j];
        }
    }  
    cout << dp[N - 1][N - 1];  
}

int main() {
    cin >> N;
    v.resize(N, vector<int>(N));
    dp.resize(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }
    dp[0][0] = 1;
    solve();
    return 0;    
}