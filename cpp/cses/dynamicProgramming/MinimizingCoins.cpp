#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n, tar;
    cin >> n >> tar;
    vector<ll> dp(tar + 3, -1);
    dp[0] = 0;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for(int i = 1; i <= tar; ++i) {
        for(int m : arr) {
            if(i >= m && dp[i - m] >= 0) {
                if(dp[i] >= 0) {
                    dp[i] = min(dp[i], dp[i - m] + 1);
                } else {
                    dp[i] = dp[i - m] + 1;
                }
            }
        }
    }

    cout << dp[tar] << "\n";
    return 0;
}