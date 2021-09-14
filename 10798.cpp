#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
    int max = 0;

    for (int i = 0; i < 5; i++) {
        string st;
        cin >> st;
        v.push_back(st);

        if (max < st.size()) {
            max = st.size();
        }
    } 

    for (int i = 0; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            if(v[j].size() >= i && v[j][i] != '\0') {
                cout << v[j][i];
            }
        }
    }
    return 0;
}