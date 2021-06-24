#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if(90 <= x && x <= 100) {
        cout << "A";
    } else if(80 <= x && x <= 89) {
        cout << "B";
    } else if(70 <= x && x <= 79) {
        cout << "C";
    } else if(60 <= x && x <= 69) {
        cout << "D";
    } else {
        cout << "F";
    }

    return 0;
}