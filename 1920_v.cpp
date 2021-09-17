//with vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void bs(int target) {
    int mid, left, right;
    left = 0, right = N - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if(v[mid] > target) {
            right = mid - 1;
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        bs(tmp);
    }
    return 0;
}