#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> v;

int numBlue = 0;
int numWhite = 0;
bool check(int top, int bottom, int left, int right) { // can divide more
    bool one = false;
    bool zero = false;
    for (int i = top; i < bottom; ++i) {
        for (int j = left; j < right; ++j) {
            if (v[i][j] == 0) {
                if (one) return true;
                zero = true;
            } else {
                if (zero) return true;
                one = true;
            }
        }
    }
    if (one && !zero) {
        numBlue++;
    }
    if (!one && zero) {
        numWhite++;
    }
    return false;
}

void solve(int top, int bottom, int left, int right) {
    if (top < bottom && left < right && check(top, bottom, left, right)) {
        int row_mid = (top + bottom) / 2;
        int col_mid = (left + right) / 2;
        solve(top, row_mid, left, col_mid);
        solve(row_mid, bottom, left, col_mid);
        solve(top, row_mid, col_mid, right);
        solve(row_mid, bottom, col_mid, right);
    }
}

int main() {
    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0 ; j < N; ++j) {
            cin >> v[i][j];
        }
    }
    solve(0, N, 0, N);
    cout << numWhite << '\n' << numBlue;
    return 0;
}