#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int two[201];
int five[201];

ll dp[201][5001];

int main(void) {
    int n, k;
    cin >> n >> k;
    
    ll in;
    for(int i = 0; i < n; ++i) {
        cin >> in;
        while(in % 2 == 0) {
            two[i]++;
            in /= 2;
        }

        while(in % 5 == 0) {
            five[i]++;
            in /= 5;
        }
    }

    for(int i = 0; i < 201; ++i) {
        for(int j = 0; j < 5001; ++j) {
            dp[i][j] = -1e16;
        }
    }

    dp[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = k; j >= 1; --j) {
            for(int l = 5000; l >= five[i]; --l) {
                dp[j][l] = max(dp[j - 1][l - five[i]] + two[i], dp[j][l]);
            }
        }
    }

    ll res = 0;
    for(ll i = 5000; i >= 1; --i) {
        if(res > i) break;
        res = max(min(dp[k][i], i), (ll) res);
    }

    cout << res << "\n";
    return 0;
}
