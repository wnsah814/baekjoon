#include <bits/stdc++.h>
using namespace std;

int main() {
    int u, v, x, y;
    cin >> u >> v;
    vector<vector<int>> A(u, vector<int>(v));
    for (int i = 0; i < u; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> x >> y;
    vector<vector<int>> B(x, vector<int>(y));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < u; ++i) {
        for (int j = 0; j < y; ++j) {
            int n = 0;
            for (int k = 0; k < v; ++k) {
                n += A[i][k] * B[k][j];
            }
            cout << n << ' ';
        }
        cout << '\n';
    }
    return 0;
}