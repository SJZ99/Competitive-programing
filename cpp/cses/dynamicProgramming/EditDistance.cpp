#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
int dp[5001][5001];
int main() { _
    string a, b;
    cin >> b >> a;

    int len1 = a.length();
    int len2 = b.length();

    for(int i = 1; i <= len2; ++i) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= len1; ++i) {
        dp[i][0] = i;
    }

    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    cout << dp[len1][len2] << "\n";
    return 0;
}