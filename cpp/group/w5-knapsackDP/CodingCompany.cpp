#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

const ll K = 5000;
const ll mod = 1000000007;

int main(void) {
    int n, x;
    cin >> n >> x;

    int t[n] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(t, t + n);

    vector<vector<ll>> dp1(n + 5, vector<ll>(x + K + 5));
    vector<vector<ll>> dp2(n + 5, vector<ll>(x + K + 5));

    dp1[0][K] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n - i; ++j) {
            for(int k = 0; k <= x + K; ++k) {
                if(dp1[j][k] == 0) continue;

                // one coder
                dp2[j][k] += dp1[j][k];
                dp2[j][k] %= mod;

                // create team with current people
                if(j + 1 < n - i) {
                    dp2[j + 1][k - t[i]] += dp1[j][k];
                    dp2[j + 1][k - t[i]] %= mod;
                }

                // put in middle
                if(j < n - i) {
                    dp2[j][k] += j * dp1[j][k];
                    dp2[j][k] %= mod;
                }
                
                // end
                if(j > 0 && (k + t[i]) <= (K + x)) {
                    dp2[j - 1][k + t[i]] += dp1[j][k] * j;
                    dp2[j - 1][k + t[i]] %= mod;
                }
            }
        }
        
        // swap
        dp1 = dp2;
        for(int j = 0; j < n - i; ++j) {
            for(int k = 0; k <= x + K; ++k) {
                dp2[j][k] = 0;
            }
        }

    }

    ll res = 0;
    for(int k = K; k <= K + x; ++k) {
        res += dp1[0][k];
        res %= mod;
    }

    cout << res << "\n";
    return 0;
}
