#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> visited;
vector<int> arr;

void dfs(int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    arr.resize(M);
    visited.resize(N + 1);
    dfs(0);

    return 0;
}