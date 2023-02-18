#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

// n / 2

// closest to total / 2

// 100 * 50 * 450
// first i people, use j people, k weight, T or F
// dp[i][j][k] =  dp[i - 1][j - 1][k -w[i]] || dp[i - 1][j][k]

// res = dp[n][n / 2][total / 2]

// compress:
// dp[i][k] = j;
// dp[i][k] = dp[i - 1][k] || (dp[i - 1][k - w[i]]) << 1
#define W 45001
long long int dp[100][W];

int main() { _
    int t;
    cin >> t;
    vector<int> arr(100);
    while(t--) {
        memset(dp, 0, W * 100 * sizeof(long long int));
        int n = 0;
        int temp;
        cin >> n;
        arr.clear();
        int sum = 0;

        for(int i = 0; i < n; ++i) {
            cin >> temp;
            sum += temp;
            arr.push_back(temp);
        }

        int tar = sum / 2;
        dp[0][arr[0]] = 1;
        for(int i = 1; i < n; ++i) {
            dp[i][arr[i]] = 1;
            for(int j = 0; j <= tar; ++j) {
                dp[i][j] |= dp[i - 1][j];
                if(j - arr[i] >= 0) {
                    dp[i][j] |= ((dp[i - 1][j - arr[i]]) << 1);
                }
            }
        }

        int find = 0;
        if(n % 2 == 0) {
            long long int used = (1LL << ((n / 2) - 1));
            for(int i = 0; i < tar; ++i) {
                if((dp[n - 1][tar - i] & used) != 0) {
                    find = tar - i;
                    break;
                }
            }
        } else {
            long long int used = (1LL << ((n / 2) - 1));
            for(int i = 0; i < tar; ++i) {
                if((dp[n - 1][tar - i] & used) != 0 || (dp[n - 1][tar - i] & (used << 1)) != 0) {
                    find = tar - i;
                    break;
                }
            }
        }
        

        if(sum - find > find) {
            cout << find << " " << sum - find << "\n";
        } else {
            cout << sum - find << " " << find << "\n";
        }
        if(t > 0) {
            cout << "\n";
        }

    }

    return 0;
}