#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    free(arr);
}