#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD 1000000007

int main() { _
    
    int tc;
    cin >> tc;

    vector<vector<ll>> dp((int) 1e6 + 1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= (int) 1e6; ++i) {
        dp[i][0] = dp[i - 1][1] + (4 * dp[i - 1][0]) % MOD;
        dp[i][1] = dp[i - 1][0] + (2 * dp[i - 1][1]) % MOD;
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    ll n;
    while(tc--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
    return 0;
}