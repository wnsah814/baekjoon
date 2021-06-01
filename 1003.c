#include <stdio.h>
int dp[41]; 
int fibonacci(int n){
    if(n <= 0){ 
        dp[0] = 0; 
        return 0; 
    }else if(n ==1){ 
        dp[1] = 1; 
        return 1; 
    } if(dp[n] != 0){ 
        return dp[n]; 
    } else { 
        return dp[n] = fibonacci(n-1) + fibonacci(n-2); 
    }
} 

int main(void){ 
    int test; 
    scanf("%d", &test); 
    while(test-- > 0){ 
        int x; 
        scanf("%d", &x); 
        if(x == 0){ 
            printf("%d %d\n", 1, 0); 
        }else if(x == 1){ 
            printf("%d %d\n", 0, 1); 
        }else{ 
            fibonacci(x); 
            printf("%d %d\n", dp[x-1], dp[x]); 
        }
    } 
    return 0; 
}