#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
// 最大連續和
int main() {
    fastio
    int n;
    cin >> n;
    while(n != 0) {
        int arr[n] = {};
        int dp[n] = {};
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        dp[0] = arr[0];
        int maxx = INT_MIN;
        for(int i = 1; i < n; ++i) {
            dp[i] = max(0, dp[i - 1]) + arr[i];
            maxx = max(maxx, dp[i]);
        }

        if(maxx <= 0) {
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is " << maxx << ".\n";
        }
        cin >> n;
    }
    return 0;
}