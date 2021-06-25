#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, L;
    string S;

    vector<pair<int, string>> v;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> S >> L;
            v.push_back({L, S});
        }
        sort(v.begin(), v.end());
        cout << v.back().second << "\n";
    }
}