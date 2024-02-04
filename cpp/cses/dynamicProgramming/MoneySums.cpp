#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MAX 100010

int main() { _
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<bool> dp(MAX, false);
    dp[arr[0]] = true;
    dp[0] = true;
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = MAX - 1; j >= 1; --j) {
            if(j - arr[i] >= 0 && dp[j - arr[i]] && !dp[j]) {
                dp[j] = true;
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    for(int i = 1; i < MAX; ++i) {
        if(dp[i]) cout << i << " ";
    }

    return 0;
}