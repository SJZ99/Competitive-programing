#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
const ll mod = 998244353ll;
ll dp[5001];

int main() { _
    int q, k;
    cin >> q >> k;

    dp[0] = 1;

    for(int i = 0; i < q; ++i) {
        string s;
        cin >> s;

        int val;
        cin >> val;

        if(s == "+") {
            for(int j = k; j >= val; --j) {
                dp[j] += dp[j - val];
                dp[j] %= mod;
            }
        } else {
            for(int j = val; j <= k; ++j) {
                dp[j] -= dp[j - val];
                dp[j] += mod;
                dp[j] %= mod;
            }
        }

        cout << dp[k] << "\n";
    }

    return 0;
}