#include <iostream>
#include <string>

using namespace std;

int reverse(int a)
{
    int h, t, o, result;
    h = a / 100;
    t = (a / 10) % 10;
    o = a % 10;
    result = o * 100 + t * 10 + h;
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;

    a = reverse(a);
    b = reverse(b);

    if (a > b)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }
    return 0;
}