#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int R;
        string s;
        cin >> R >> s;
        for (int l = 0; l < s.length(); l++)
        {
            for (int j = 0; j < R; j++)
            {
                cout << s[l];
            }
        }
        cout << "\n";
    }
}