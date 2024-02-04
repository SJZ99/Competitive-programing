#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n, m;
    cin >> n >> m;

    int *dp[n];
    for(int i = 0; i < n; ++i) {
        dp[i] = (int*) calloc(n, sizeof(int));
    }

    char c;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> c;
            
            if(i >= 1) {
                dp[i][j] += dp[i - 1][j];
            }

            if(j >= 1) {
                dp[i][j] += dp[i][j - 1];
            }

            if(i >= 1 && j >= 1) {
                dp[i][j] -= dp[i - 1][j - 1];
            }

            if(c == '*') {
                dp[i][j]++;
            }
        }
    }

    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, x2--, y1--, y2--;

        int res = dp[x2][y2];
        if(y1 >= 1) {
            res -= dp[x2][y1 - 1];
        }

        if(x1 >= 1) {
            res -= dp[x1 - 1][y2];
        }

        if(y1 >= 1 && x1 >= 1) {
            res += dp[x1 - 1][y1 - 1];
        }
        cout << res << "\n";
    }

    return 0;
}