#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int makeNum(int index, int len) {
    int n = 0;
    for (int i = len - 1; i >= 0; --i) {
        n += v[index + len - i - 1] * pow(10, i);
    }
    return n;
}

int main() {
    string str;
    cin >> str;
    
    for (char c : str) {
        v.push_back(c - '0');
    }
    int max = -1, small, l;
    for (l = 1; l <= 3; ++l) {
        if (l > v.size()) break;
        small = makeNum(0, l);
        if (small == 9 && makeNum(1, 2) == 10) break;
        if (small == 99 && makeNum(1, 3) == 100) break;
        if (small == 999) {
            cout << "999 999";
            return 0;
        }

        if (small + 1 == makeNum(l, l)) {
            if (v.size() >= 6 && makeNum(0, l + 2) + 1 == makeNum(l + 2, l + 2)) {
                small = makeNum(0, l+2);
                l = 3;
                break;
            }
            if (v.size() >= 4 && makeNum(0, 2) + 1 == makeNum(2, 2)) {
                small = makeNum(0, 2);
                l = 2;
                break;
            }
            if (v.size() >= 3 && makeNum(1, 1) == makeNum(2, 1)) {
                small = makeNum(0, 3);
                l = 3;
                break;
            }

            break;
        }
    }
    for (int ll = l; ll <= 3; ++ll) {
        if (makeNum(v.size() - 2 * ll, ll) + 1 == makeNum(v.size() - ll, ll)) {
            max = makeNum(v.size() - ll, ll);
        }
    }
    if (max < 0) {
        cout << small << ' ' << small;
        return 0;
    }
    cout << small << ' ' << max;
    return 0;
}