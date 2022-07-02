#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int n : arr) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; ++i) {
        arr[cnt] = i;
        dfs(i, cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    arr.resize(M);
    dfs(1, 0);
    return 0;
}