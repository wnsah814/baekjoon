#include <bits/stdc++.h>
using namespace std;
int N, K;

void solve() {
    int x = N;
    int cnt = 0;
    while (true) {
        if (2 * x < K) {
            
            x *= 2;
        } else if (2 * x > K) {
            if (2 * x - K > K - x) {
                x++;
            } else {
                x *= 2;
            }
        }
        cnt++;
    }
}


int main() {
    cin >> N >> K;
    solve();
    return 0;
}