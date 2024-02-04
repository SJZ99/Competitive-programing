#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _

    int n;
    cin >> n;
    
    vector<int> arr(n, 0);
    vector<ll> prefix(n + 1, 0);
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i][i] = arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for(int len = 2; len <= n; ++len) {
        for(int i = 0; i < n - len + 1; ++i) {
            int to = i + len - 1;

            dp[i][to] = arr[i] + (prefix[to + 1] - prefix[i + 1]) - dp[i + 1][to];
            dp[i][to] = max(dp[i][to], arr[to] + (prefix[to] - prefix[i]) - dp[i][to - 1]);
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}