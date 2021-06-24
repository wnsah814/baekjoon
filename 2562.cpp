#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int main() {
    int x;

    for(int i=0; i<9; i++) {
        cin >> x;
        v.push_back(x);    
    }

    sort(v.begin(), v.end());

    
}