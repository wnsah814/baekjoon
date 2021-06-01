#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> s;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int a;
            cin >> a;
            s.push(a);
        }
        else if(str == "pop") {
            if(s.empty()==0) {
                cout << s.top() << "\n";
                s.pop();
            } else {
                cout << "-1\n";
            }
        }
        else if(str == "size")
            cout << s.size() << "\n";
        else if(str == "empty")
            cout << s.empty() << "\n";
        else if(str == "top")
            cout << s.top() << "\n";
    }


    return 0;
}