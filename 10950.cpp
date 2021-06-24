#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n>0) {
        int a, b;
        cin >> a >> b;
        cout << a+b << "\n";
        n--;
    }

    return 0;
}