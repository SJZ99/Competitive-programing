#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define MOD ((int) 1e9 + 7)

using namespace std;

int dp[(int)1e6 + 2] = {};
int main() { _
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    if(n > 6) {
        for(int i = 7; i <= n; ++i) {
            for(int j = 1; j <= 6; ++j) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}