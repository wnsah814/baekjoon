#include <bits/stdc++.h>
using namespace std;

signed main() {
    int A, B, V;
    cin >> A >> B >> V;
    int days = ceil((V-A) / (double)(A-B)) + 1;
    cout << days;
    return 0;
}