#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD 1000000007

int main() { _
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<ll>> dp(n, vector<ll>(n));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '*') {
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == '*') continue;

            if(i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }

            if(j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}