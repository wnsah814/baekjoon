#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<int> arr;
vector<int> visited;

void dfs(int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[cnt] = v[i];
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    v.resize(N);
    arr.resize(M);
    visited.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}