#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;

void dfs(int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        arr[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    arr.resize(M);
    dfs(0);
    return 0;
}