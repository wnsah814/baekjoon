#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, string>> v;

int main() {
    int N;
    cin >> N;
    while(N) {
        for(int i = 0; i < N ; i++) {
            string name;
            getline(cin, name);
            v.push_back({0, name});
        }
        string temp;
        for(int x = 0; x < 2*N-1; x++) {
            getline(cin, temp);
            cout << temp[0] << endl;
        }
        cout << "new start" << endl;
        cin >> N;
    }
}