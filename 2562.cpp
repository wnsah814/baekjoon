#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
    for(int i=1; i<=9; i++) {
        int n;
        cin >> n;
        v.push_back({n, i});
    }
    sort(v.begin(), v.end());
    cout << v.back().first << "\n" << v.back().second; 

    return 0;
}
