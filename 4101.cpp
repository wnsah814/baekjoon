#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; 
    cin >> a >> b;
    while (a != 0 && b != 0) {
        (a > b) ? cout << "Yes\n" : cout << "No\n";
        cin >> a >> b;
    }
    return 0;
}