#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define d(x) cout << x << "\n";
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        long long int dp[s.size() + 1]= {0};
        long long int temp = 0;
        bool greaterThanZero = false;
        for(int i = 0; i < s.size(); ++i) {
            greaterThanZero = i;
            temp = s[i] - '0';
            if(temp == 0) {
                dp[i] = max((greaterThanZero ? dp[i - 1] : 0), dp[i]);
                continue;
            }
            dp[i] = max(dp[i], temp + (greaterThanZero ? dp[i - 1] : 0));
            for(int j = 1; j <= 10; ++j) {

                if(i + j <= s.size() - 1) {
                    temp *= 10;
                    temp += s[i + j] - '0';
                    
                    if(temp <= INT_MAX) {
                        // d(temp)
                        dp[i + j] = max(temp + (greaterThanZero ? dp[i - 1] : 0), dp[i + j]);
                    } else {
                        break;
                    }  
                } else {
                    break;
                }
            }
        }
        long long int maxx = LONG_LONG_MIN;
        for(int i = 0; i < s.size(); ++i) {
            maxx = max(maxx, dp[i]);
            // cout << dp[i] << " ";
        }
        // d("");
        cout << maxx << "\n";
    }
    return 0;
}