#include <stdio.h>

int main() {
    int arr[] = {0, 8, 1, 4};
    printf("%ld %d %d\n", sizeof(arr), arr[1], *(arr + 2));
    return 0;
}