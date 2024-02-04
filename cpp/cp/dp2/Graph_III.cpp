#include <bits/stdc++.h>
#include <climits>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MAX LLONG_MAX
using namespace std;

unsigned long long int dp[501][501];

int main() { _
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = MAX;
        }
        dp[i][i] = 0;
    }

    for(int i = 0; i < m; ++i) {
        unsigned long long int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dp[a][b] = min(c, dp[a][b]);
        dp[b][a] = min(c, dp[b][a]);
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int u, v;
    for(int i = 0; i < q; ++i) {
        cin >> u >> v;
        if(dp[u - 1][v - 1] >= MAX) {
            cout << "-1\n";
        } else {
            cout << dp[u - 1][v - 1] << "\n";
        }
    }

    return 0;
}