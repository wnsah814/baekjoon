#include <stdio.h>

int arr[1005][3];

int Min(int a, int b) {
    if(a > b) return b;
    return a;
}

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i< N; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    for(int i=0; i < N ; i ++) {
        arr[i][0] += Min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] += Min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] += Min(arr[i-1][0], arr[i-1][1]);    
    }

    //N-1��° �迭�� �ּҰ� 3���� ����Ǿ� �ִ�.
    //�ּ� 3���� ���� ���� ���� ������ ��.
    int m = Min(Min(arr[N-1][0], arr[N-1][1]), arr[N-1][2]);

    printf("%d", m); 
}