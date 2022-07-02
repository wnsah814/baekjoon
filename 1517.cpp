#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tmp;
long long cnt = 0;

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1;
    int t = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        } else {
            cnt += mid - i + 1;
            tmp[t++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[t++] = arr[i++];
    }
    while (j <= right) {
        tmp[t++] = arr[j++];
    }
    for (int k = left; k <= right; ++k) {
        arr[k] = tmp[k];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;
    arr.resize(N);
    tmp.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    mergeSort(0, N-1);
    cout << cnt << '\n';
    return 0;
}