#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    double sum = 0;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        sum += x;

        if (x > max)
        {
            max = x;
        }
    }
    double result = (sum / N) / max * 100;
    cout << result;

    return 0;
}