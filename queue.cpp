#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "front : " << q.front() << "\n";
    cout << "back : " << q.back() << "\n";
    cout << "size : " << q.size() << "\n";
    cout << "empty : " << q.empty() << "\n";

    q.pop();
    cout << "after pop once \n";
    cout << "front : " << q.front() << "\n";
    cout << "back : " << q.back() << "\n";
    cout << "size : " << q.size() << "\n";
    cout << "empty : " << q.empty() << "\n";

    q.pop();
    cout << "after pop once \n";
    cout << "front : " << q.front() << "\n";
    cout << "back : " << q.back() << "\n";
    cout << "size : " << q.size() << "\n";
    cout << "empty : " << q.empty() << "\n";

    q.pop();
    cout << "after pop once \n";
    cout << "front : " << q.front() << "\n";
    cout << "back : " << q.back() << "\n";
    cout << "size : " << q.size() << "\n";
    cout << "empty : " << q.empty() << "\n";    
}