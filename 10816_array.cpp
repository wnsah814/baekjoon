//baekjoon 10816 with array

#include <iostream>
#include <algorithm>

using namespace std;

int lower_binary(int* arr, int target, int size) {
    int mid, left, right;
    left = 0, right = size - 1;

    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}
int upper_binary(int* arr, int target, int size) {
    int mid, left, right;
    left = 0, right = size - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i]; 
    }
    sort(arr, arr+N);

    int M, tmp, u, l, r;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        u = upper_binary(arr, tmp, N);
        l = lower_binary(arr, tmp, N);
        if (u == N - 1 && arr[N-1] == tmp) u++;
        r = u - l;
        cout << r << " ";
    }

    return 0;
}