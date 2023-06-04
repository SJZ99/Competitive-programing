#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int arr[5001];
int dp[5001];

int main() { _
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int mmmax = 0;
    for(int i = 0; i < n; ++i) {
        int mmax = 0;
        for(int j = 0; j < i; ++j) {
            if(arr[i] > arr[j]) {
                mmax = max(dp[j], mmax);
            }
        }
        dp[i] = mmax + 1;
        mmmax = max(dp[i], mmmax);
    }

    printf("%d\n", mmmax);

    return 0;
}