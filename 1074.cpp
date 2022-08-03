#include <bits/stdc++.h>
using namespace std;

int N, r, c;
vector<vector<int>> v;

int idx = 0;

void solve(int top, int bottom, int left, int right) {
    if (top > bottom || left > right) return;
    int row_mid = (top + bottom) / 2;
    int col_mid = (left + right) / 2;
    
    solve(top, row_mid, left, col_mid);
    solve(top, row_mid, col_mid, right);
    solve(row_mid, bottom, left, col_mid);
    solve(row_mid, bottom, col_mid, right);
}

int main() {
    cin >> N >> r >> c;
    N = 1 << N;
    cout << N;
    v.resize(N, vector<int>(N));
    solve(0, N, 0, N);
    cout << v[r][c];
    return 0;
}