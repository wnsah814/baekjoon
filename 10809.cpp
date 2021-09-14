#include <iostream>
#include <vector>

using namespace std;

vector<int> v(26);

int main() {
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        if(v[S[i] - 'a'] == 0) {
            v[S[i] - 'a'] = i+1;
        }
    }

    for(int i = 0; i < 26; i++) {
        v[i]--;
        cout << v[i] << " ";
    }

}