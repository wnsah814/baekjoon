#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(10));

    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i-1][k] % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    long long ans = 0;
    for (int i : dp[N]) {
        ans += i % MOD;
    }
    ans %= MOD;
    cout << ans;
    return 0;
}