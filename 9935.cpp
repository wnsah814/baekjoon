#include <bits/stdc++.h>
using namespace std;

void solve(string str, string code) {
    vector<char> v;
    for (int i = 0; i < str.length(); ++i) {
        v.push_back(str[i]);

        if (v.size() >= code.length()) {
            bool bomb = true;
            for (int j = 0; j < code.length(); ++j) {
                if (v[v.size() - code.length() + j] != code[j]) {
                    bomb = false;
                    break;
                }
            }
            if (bomb) {
                for (int j = 0; j < code.length(); ++j) {
                    v.pop_back();
                }
            }
        }
    }

    if (v.empty()) {
        cout << "FRULA\n";
    } else {
        for (char c : v) {
            cout << c;
        }
        cout << '\n';
    }
}

int main() {
    string str, code;
    cin >> str >> code;
    solve(str, code);
    return 0;
}