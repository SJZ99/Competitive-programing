#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
int dp[5001][5001];
int main() { _
    string a, b;
    cin >> a >> b;

    int len1 = a.length();
    int len2 = b.length();
    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            
            if(a[i - 1] == b[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    if(dp[len1][len2] * 2 > len1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}