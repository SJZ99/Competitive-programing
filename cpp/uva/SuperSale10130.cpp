#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        int total = 0;

        cin >> n;
        int price[n] {0};
        int weight[n] {0};
        int dp[n][31] {0};

        for(int i = 0; i < n; ++i) {
            cin >> price[i] >> weight[i];
        }

        for(int i = weight[0]; i <= 30; ++i) {
            dp[0][i] = price[0];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= 30; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);

                if(j >= weight[i]) {
                    dp[i][j] = max(dp[i][j], price[i] + dp[i - 1][j - weight[i]]);
                }
            }
        }

        cin >> p;
        for(int i = 0; i < p; ++i) {
            int capacity;
            cin >> capacity;
            total += dp[n - 1][capacity];
            // cout << dp[n - 1][capacity] << " ";
        }

        cout << total << "\n";
    }

    return 0;
}