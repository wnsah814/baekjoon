#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int N, arr[MAX];

void Bin_Search(int value) {
    int mid, left = 0, right = N - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (value < arr[mid]) {
            right = mid - 1;
        }
        else if (value > arr[mid]) {
            left = mid + 1;
        }
        else {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    sort(arr, arr+N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        Bin_Search(tmp);
    } 
    return 0;
}