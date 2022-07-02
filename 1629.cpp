#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll exp(int a, int b, int c) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % c;
    }
    ll temp = exp(a, b/2, c);
    if (b % 2 == 1) {
        return temp * temp % c * a % c;
    } else {
        return temp * temp % c;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << exp(A, B ,C);
    return 0;
}