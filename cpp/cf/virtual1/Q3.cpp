#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        int arr[n] = {};
        cin.ignore();
        getline(cin, s);
        s.reserve(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int dp[n][2] = {0};
        int last = -1;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                if(i - 1 >= 0) {
                    // cout << last << "\n";
                    dp[i][0] = max(dp[i - 1][0], (((i - last) > 1) ? dp[i - 1][1] : -1)) + arr[i - 1];
                    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i]; 
                } else {
                    dp[i][0] = 0;
                    dp[i][1] = arr[i];
                }
                last = i;
                
            } else {
                if(i - 1 >= 0) {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1];
                } else {
                    dp[i][0] = 0;
                    dp[i][1] = 0;
                }
                
            }
            // cout << dp[i][0] << " " << dp[i][1] << " \n";
        }
        // for(int i = 0; i < n; ++i) {
        //     cout << dp[i][0] << " " << dp[i][1] << " \n";
        // }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
    return 0;
}