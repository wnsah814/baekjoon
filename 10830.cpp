#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvll = vector<vector<ll>>;

int N;
ll B;

vvll mul(vvll& a, vvll& b) {
    vvll C(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ll tmp = 0;
            for (int k = 0; k < N; ++k) {
                tmp += a[i][k] * b[k][j];
            }
            C[i][j] = tmp % 1000;
            // C[i][j] = (tmp == 1000) ? tmp : (tmp % 1000);
        }
    }
    return C;
}

int main() {
    cin >> N >> B;
    vvll A(N, vector<ll>(N));
    vvll C(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
        C[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) {
            C = mul(C, A);
        }
        A = mul(A, A);
        B /= 2;
    }

    for (auto v : C) {
        for (auto e : v) {
            cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}