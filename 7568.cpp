#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> order(N, 1);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i].first < v[j].first &&  v[i].second < v[j].second) {
                order[i]++;
            }
        }
    }
    
    for (int n : order) {
        cout << n << ' ';
    }
    return 0;
}