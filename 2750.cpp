#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; 
    cin >> N;

    vector<int> v;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "\n";
    }

    return 0;
}