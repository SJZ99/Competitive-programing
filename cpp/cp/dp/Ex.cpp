#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<vector<int>> dp(1002, vector<int>(1002, 0));

int main() { _
    int n, q;

    cin >> n >> q;

    char c;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> c;
            // cout << c << "--";
            if(c == '*') dp[i][j] = 1;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            // cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << "\n";
    }

    return 0;
}