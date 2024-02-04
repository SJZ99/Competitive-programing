#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int a, b;
    cin >> a >> b;

    if(b > a) {
        int t = a;
        a = b;
        b = t;
    }

    vector<vector<ll>> dp(501, vector<ll>(501, INT_MAX));

    for(int i = 0; i <= a; ++i) {
        for(int j = 0; j <= b; ++j) {
            if(i == j) {
                dp[i][j] = 0;
            } else {
                for(int k = 1; k <= i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }

                for(int k = 1; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << dp[a][b] << "\n";
    return 0;
}