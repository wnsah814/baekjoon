#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int x;

    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);    
    }

    sort(v.begin(), v.end());

    cout << v.front() << " " << v.back();

    return 0;
}