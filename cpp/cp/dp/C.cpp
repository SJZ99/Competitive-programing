#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MAX (int) (1e6 + 500)
using namespace std;

vector<int> dp(1000001, MAX);
int main() { _
    int n ,x;
    cin >> n >> x;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= x; ++j) {
            if(j >= arr[i]) {
                dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
            }
        }
    }

    if(dp[x] == MAX) cout << "-1\n";
    else cout << dp[x] << "\n";

    return 0;
}