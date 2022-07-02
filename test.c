#include <stdio.h>

int main() {
    int arr[3];
    int offset = &arr[0] - arr;
    printf("%p - %p = %d", &arr[0], arr, offset);
    return 0;
}