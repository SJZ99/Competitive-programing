#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(false);
#define d(x) cout << x << "\n";
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        long long int arr[a][b][c];
        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                for(int k = 0; k < c; ++k) {
                    cin >> arr[i][j][k];
                }
            }
        }

        long long int dp[c] = {};
        long long int maxx = LONG_LONG_MIN;
        for(int i = 0; i < a; ++i) {
            for(int j = i; j < a; ++j) {

                // create combination of multi-plane
                long long int tm[b][c] = {};
                for(int k = 0; k < b; ++k) {
                    for(int l = 0; l < c; ++l) {
                        for(int m = i; m <= j; ++m) {
                            tm[k][l] += arr[m][k][l];
                        }
                    }
                }

                // for(int k = 0; k < b; ++k) {
                //     for(int l = 0; l < c; ++l) {
                //         d(tm[k][l])
                //     }
                // }

                for(int k = 0; k < b; ++k) {
                    for(int l = k; l < b; ++l) {
                        // create combination of multi-line
                        long long int tl[c] = {};
                        for(int m = 0; m < c; ++m) {
                            for(int n = k; n <= l; ++n) {
                                tl[m] += tm[n][m];
                            }
                        }

                        // for(int m = 0; m < c; ++m) {
                        //     d(tl[m])
                        // }
                        // init dp
                        for(int m = 0; m < c; ++m) {
                            dp[m] = 0;
                        }

                        dp[0] = tl[0];
                        maxx = max(dp[0], maxx);
                        
                        for(int m = 1; m < c; ++m) {
                            dp[m] = max(0ll, dp[m - 1]) + tl[m];
                            if(dp[m] > maxx) {
                                maxx = dp[m];
                            }
                            // d(dp[m] << " ")
                        }
                        // d("")
                    } 
                }
            }
        }
        cout << maxx << "\n";
        if(t != 0) {
            cout << "\n";
        }
    }
    return 0;
}