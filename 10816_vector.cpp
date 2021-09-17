// baekjoon 10816 with vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int M;
    cin >> M;
    int tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        auto lower = lower_bound(v.begin(), v.end(), tmp);
        auto upper = upper_bound(v.begin(), v.end(), tmp);
        cout << upper - lower << " ";
    }
    
    return 0;
}