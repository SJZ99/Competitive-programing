#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int h[200001];

void dfs(int curr, int from, vector<vector<int>>& adj) {
    h[curr] = h[from]+1;

    for(int nei : adj[curr]) {
        if(nei != from) {
            if(nei != from) {
                dfs(nei, curr, adj);
            }
        }
    } 
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int dp[n+1][18] = {};
    vector<vector<int>> adj(n+1);

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 18; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[1][0] = 1;

    for(int i = 2; i <= n; ++i) {
        cin >> dp[i][0];
        adj[i].push_back(dp[i][0]);
        adj[dp[i][0]].push_back(i);
    }

    for(int j = 1; j < 18; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(dp[i][j-1] != -1) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            } else {
                dp[i][j] = -1;
            }
        }
    }

    for(int nei : adj[1]) {
        dfs(nei, 1, adj);
    }

    int a, b;
    while(q--) {
        cin >> a >> b;

        // lift to same level
        if(h[a] > h[b]) {
            int up = h[a] - h[b];
            for(int i = 0; i < 18; ++i) {
                if(up & (1 << i)) {
                    a = dp[a][i];
                }
            }
        } else if(h[b] > h[a]) {
            int up = -h[a] + h[b];
            for(int i = 0; i < 18; ++i) {
                if(up & (1 << i)) {
                    b = dp[b][i];
                }
            }
        }

        if(a == b) {
            cout << a << "\n";
            continue;
        }

        // cout << a << " " << b << "\n";

        // find LCA
        int from = 17;
        
        for(from; from >= 0; --from) {
            if(dp[a][from] != -1 && dp[b][from] != -1 && dp[a][from] != dp[b][from]) {
                // cout << from << " " << dp[a][from] << " " << dp[b][from] << "\n";
                a = dp[a][from];
                b = dp[b][from];
            }
        }
        
        cout << dp[a][0] << "\n";
    }

    return 0;
}