#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    queue<int> q;

    for(int i=0; i<N; i++) {
        q.push(i+1);
    }

    cout << "<";

    while(!q.empty()) {
        for(int i=0; i<K-1; i++) {
            q.push(q.front());
            q.pop();
        }
        if(q.size() != 1) {
            cout << q.front() << ", ";
        } else {
            cout << q.front();
        }
        q.pop();
    }
    cout << ">";
    return 0;
}