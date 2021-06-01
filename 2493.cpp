#include<iostream>
#include<stack>

using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    stack<pair<int, int>> ms;

    ms.push({2147483647, 0});

    int h;
    for(int i = 1; i <= N; i++) {
        cin >> h;
        while(ms.top().first < h)
            ms.pop();
        cout << ms.top().second << " ";
        ms.push({h, i});
    }

    return 0;
}