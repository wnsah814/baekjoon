#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

vector<vector<ll>> dp;

ll nCr(int n, int r) {
    if (r == 0 || r == n) return 1;
    if (dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = nCr(n-1, r-1) + nCr(n-1, r); 
}

int main() {
    int n, m;
    cin >> n >> m;
    dp.resize(n+1, vector<ll>(m+1, -1));
    cout << nCr(n, m);
    return 0;
}