#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD 1000000007
int main() { _
    int n, tar;
    cin >> n >> tar;
    vector<ll> dp(tar + 3, 0);
    dp[0] = 1;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for(int i = 1; i <= tar; ++i) {
        for(int m : arr) {
            if(i >= m && dp[i - m] >= 0) {
                dp[i] += dp[i - m];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[tar] << "\n";
    return 0;
}