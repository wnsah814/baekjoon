#include <iostream>
#include <vector>
using namespace std;

vector<int> v(26);

int main() {
    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        v[s[0] - 'a']++;   
    }

    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if(v[i]>=5) {
            cout << char('a'+i);
            flag = 1;
        }
    }
    if(flag == 0) {
        cout << "PREDAJA\n";
    }

    return 0;
}