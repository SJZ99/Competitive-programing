#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    
    int n;
    while(cin >> n) {
        vector<int> arr(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // sort(arr.begin(), arr.end());

        int dp[255][255] = {0};
        int w[255][255] = {0};
        for(int i = 0; i < n; ++i) {
            w[i][i] = arr[i];
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(i == j) continue;
                w[i][j] = w[i][j - 1] + arr[j];
            }
        }

        for(int i = 0; i < 255; ++i) {
            for(int j = 0; j < 255; ++j) {
                dp[i][j] = 1500000;
            }
        }

        for(int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for(int i = 1; i <= n; ++i) { // how many
            for(int j = 0; j <= n - i; ++j) { // start from
                int last = j + i - 1;

                dp[j][last] = min(dp[j][last], dp[j + 1][last] + w[j][last] - arr[j]);

                for(int k = j + 1; k <= j + i - 2; ++k) {
                    dp[j][last] = min(dp[j][last], dp[j][k - 1] + dp[k + 1][last] + w[j][last] - arr[k]);
                }

                dp[j][last] = min(dp[j][last], dp[j][last - 1] + w[j][last] - arr[last]);                
            }
        }
        cout << dp[0][n - 1] << "\n";
    }

    return 0;
}