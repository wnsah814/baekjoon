#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    c = c ^ (1 << 5);
    cout << c << endl;
    return 0;
}