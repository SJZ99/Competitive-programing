#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { 
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n + 1, vector<char>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }

    bool contra = false;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {

            if(grid[i][j] == 'B') {
                for(int k = 1; k <= i; ++k) {
                    for(int l = 1; l <= j; ++l) {
                        if(grid[k][l] != 'R')
                            grid[k][l] = 'B';
                        else {
                            contra = true;
                            break;
                        }
                    }
                }
            } else if(grid[i][j] == 'R') {
                for(int k = i; k <= n; ++k) {
                    for(int l = j; l <= m; ++l) {
                        if(grid[k][l] != 'B')
                            grid[k][l] = 'R';
                        else {
                            contra = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(contra) {
        cout << "0\n";
        return 0;
    }
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, 0));

    for(int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= m; ++i) {
        dp[n + 1][i] = 1;
    }

    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            if(grid[i][j] == '.') {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
            } else if(grid[i][j] == 'B') {
                dp[i][j] = dp[i + 1][j];
            } else if(grid[i][j] == 'R') {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[1][m] << "\n";


    return 0;
}