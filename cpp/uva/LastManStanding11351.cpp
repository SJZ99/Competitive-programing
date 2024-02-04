#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int dp[(int)1e6 + 10] = {0};

int main() { _
    int tc;
    cin >> tc;
    int cnt = 1;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        
        memset(dp, 0, ((int)1e6 + 10) * sizeof(int));
        
        dp[1] = 0;
        for(int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + k) % i;
        }

        for(int i = 1; i <= n; ++i) {
            cout << dp[i] << " ";
        }
        cout << "\n";
        cout << "Case " << cnt++ << ": " << dp[n] + 1 << "\n";
    }

    return 0;
}