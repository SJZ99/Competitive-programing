#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long int dp[31] = {0};
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3; i < 31; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int yr = 0;
    while(scanf("%d", &yr) != EOF) {
        printf("%d\n", dp[yr]);
    }
    return 0;
}