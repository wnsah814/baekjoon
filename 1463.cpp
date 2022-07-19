#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int cnt = 0;
    while (n != 1) {
        if (n % 2 == 0 ) {

        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n--;
        }
        cout << "n: " << n << endl;
        cnt++;
    }
    cout << cnt;
}

int main() {
    int N;
    cin >> N;
    solve(N);
    return 0;
}