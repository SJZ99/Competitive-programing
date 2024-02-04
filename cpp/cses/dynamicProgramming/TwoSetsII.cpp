#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MOD (int) (1e9 + 7)

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;

    ll tar = n * (n + 1) / 2;
    if(tar % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    tar /= 2;

    vector<ll> dp(tar + 1, 0);
    dp[0] = 1;

    for(int i = n; i >= 1; --i) {
        for(int j = tar; j >= 1; --j) {
            if(j - i >= 0 && dp[j - i] > 0) {
                dp[j] += dp[j - i];
                // cout << j << " from " << j - i << "\n";
                dp[j] %= MOD;
            }
        }
    }

    ll ans = dp[tar] * 500000004ll;
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}