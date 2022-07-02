#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int A, B, V;
    cin >> A >> B >> V;
    int current = 0;
    int days = 1;
    while (1) {
        if ((current = current + A) >= V) {
            break;
        }
        days++;
        current -= B;
    }
    cout << days;
    return 0;
}