#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    while (1)
    {
        int a[3] = {};
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
        {
            break;
        }

        sort(begin(a), end(a));

        if (pow(a[0], 2) + pow(a[1], 2) == pow(a[2], 2))
        {
            cout << "right\n";
        }
        else
        {
            cout << "wrong\n";
        }
    }

    return 0;
}