#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dwarf[9];
    int x=0;
    
    for(int i=0; i<9; i++) {
        cin >> dwarf[i];
        x += dwarf[i];
    }

    x -= 100;

    for(int i=0; i<9; i++) {
        for(int j=0; j<i; j++) {
            if(dwarf[i] + dwarf[j] == x) {
                dwarf[i] = 0, dwarf[j] = 0;
                sort(dwarf, dwarf+9);

                for(int k=2; k<9; k++) {
                    cout << dwarf[k] << "\n";
                }
                return 0;
            }
        }
    }

}