#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x < X) {
            v.push_back(x);
        }
    }
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}