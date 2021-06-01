#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    queue<int> q;

    for(int i=0; i<T; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int a;
            cin >> a;
            q.push(a);
        } else if(str == "pop") {
            if(q.size() == 0) {
                cout << "-1" << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(str == "size") {
            cout << q.size() << "\n";
        } else if(str == "empty") {
            cout << q.empty() << "\n";
        } else if(str == "front") {
            cout << q.front() << "\n";
        } else if(str == "back") {
            cout << q.back() << "\n";
        }
    }
}