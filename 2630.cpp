#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> v;

int numPaper = 0;
int numSplit = 0;
bool check(int top, int bottom, int left, int right) {
    for (int i = top; i < bottom; ++i) {
        for (int j = left; j < right; ++j) {
            if (v[i][j] == 0) {
                return true;
            }
        }
    }
    numPaper++;
    return false;
}

void solve(int top, int bottom, int left, int right) {
    if (top < bottom && left < right && check(top, bottom, left, right)) {
        int row_mid = (top + bottom) / 2;
        int col_mid = (left + right) / 2;
        solve(top, row_mid, left, col_mid);
        solve(row_mid + 1, bottom, left, col_mid);
        solve(top, row_mid, col_mid + 1, right);
        solve(row_mid + 1, bottom, col_mid + 1, right);
        numSplit++;
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
    cout << numPaper << " " << numSplit;
    return 0;
}