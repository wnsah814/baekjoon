#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int G;
        cin >> G;
        vector<int> num(G);
        for (int j = 0; j < G; ++j) {
            cin >> num[j];
        }

        int k;
        for (k = 1; ; ++k) {
            int m = num[0] % k;
            bool ckeck = false;
            for (int t = 1; i < G; ++t) {
                if (num[t] % k != m) {
                    check = true;
                }
            }

        }
    }
}