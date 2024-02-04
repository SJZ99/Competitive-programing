#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

bool dp[501][501][501];
int arr[501];

int main() { _
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    dp[0][0][0] = true;
    dp[0][arr[0]][0] = true;
    dp[0][arr[0]][arr[0]] = true;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            for(int l = 0; l <= j; ++l) {
                dp[i][j][l] = dp[i - 1][j][l];

                if(j - arr[i] >= 0) {
                    dp[i][j][l] |= dp[i - 1][j - arr[i]][l];
                }

                if(j - arr[i] >= 0 && l - arr[i] >= 0) {
                    dp[i][j][l] |= dp[i - 1][j - arr[i]][l - arr[i]];
                }
            }
        }
    }

    vector<int> res;
    res.reserve(500);

    for(int i = 0; i <= k; ++i) {
        if(dp[n - 1][k][i]) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for(int i : res) {
        cout << i << " ";
    }
    return 0;
}