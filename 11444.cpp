#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvll = vector<vector<ll>>;
ll n;
const long long MOD = 1000000007;

vvll multiple(vvll& a, vvll& b) {
    vvll c(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

int main() {
    cin >> n;
    vvll ans = {{1, 0}, {0, 1}};
    vvll v = {{1, 1}, {1, 0}};
    while (n > 0) {
        if (n % 2 == 1) {
            ans = multiple(ans, v);
        }
        v = multiple(v, v);
        n /= 2;
    }   
    cout << ans[0][1];
    return 0;
}