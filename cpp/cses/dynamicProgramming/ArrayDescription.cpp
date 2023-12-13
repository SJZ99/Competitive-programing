#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD 1000000007

int main() { _
    int n, m;
    cin >> n >> m;

    vector<ll> arr(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    if(arr[0] != 0) {
        dp[0][arr[0]] = 1;
    } else {
        for(int i = 1; i <= m; ++i) {
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; ++i) {
        if(arr[i] != 0) { // fixed
            for(int k = -1; k <= 1; ++k) {
                if(arr[i] + k >= 1 && arr[i] + k <= m) {
                    dp[i][arr[i]] += dp[i - 1][arr[i] + k];
                    dp[i][arr[i]] %= MOD;
                }   
            }
        } else { // unknown
            for(int j = 1; j <= m; ++j) {
                for(int k = -1; k <= 1; ++k) {
                    if(j + k >= 1 && j + k <= m) {
                        dp[i][j + k] += dp[i - 1][j];
                        dp[i][j + k] %= MOD;
                    }
                }
            }
        }
    }

    ll total = 0;
    for(int i = 0; i <= m; ++i) {
        total += dp[n - 1][i];
        total %= MOD;
    }
    cout << total << "\n";
    return 0;
}