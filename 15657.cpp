#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<int> arr;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < N; ++i) {
        arr[cnt] = v[i];
        dfs(i, cnt + 1);
    }   
}

int main() {
    cin >> N >> M;
    v.resize(N);
    arr.resize(M);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
    return 0;
}