#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> visited;

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    arr.resize(M);
    visited.resize(N + 1);
    dfs(1, 0);
    return 0;
}