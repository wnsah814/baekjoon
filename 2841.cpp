#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P;
    cin >> N >> P;

    stack<int> s[7];

    int moves = 0;

    for(int i=0; i<N; i++) {
        int string, fret;

        cin >> string >> fret;

        if(s[string].empty()) {
            moves++;
            s[string].push(fret);
        } else {
            if(fret > s[string].top()) {
                s[string].push(fret);
                moves++;
            } else if(fret == s[string].top()) {
                continue;
            } else {
                while(!s[string].empty() && fret < s[string].top()) {
                    s[string].pop();
                    moves++;
                }
                if(!s[string].empty() && s[string].top() == fret) {
                    continue;
                }
                s[string].push(fret);
                moves++;
            }
        }
    }

    cout << moves << "\n";

    return 0;
}