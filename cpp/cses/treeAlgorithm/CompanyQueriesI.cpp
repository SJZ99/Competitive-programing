#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int dp[n+1][18] = {};
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 18; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[1][0] = -1;

    for(int i = 2; i <= n; ++i) {
        cin >> dp[i][0];
    }

    for(int j = 1; j < 18; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(dp[i][j-1] != -1) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            } else {
                dp[i][j] = -1;
            }
        }
    }

    int x, k;
    while(q--) {
        cin >> x >> k;
        int res = -1;
        for(int i = 0; i < 32; ++i) {
            if(k & (1 << i)) {
                if(res == -1) {
                    res = dp[x][i];
                } else {
                    res = dp[res][i];
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}