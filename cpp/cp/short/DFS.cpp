#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

void dfs(vector<vector<int>>& adj, bool hasVisited[], int me, int n) {
    if(me >= 1 && me <= n) {
        cout << me << " ";
        hasVisited[me] = true;
        vector<int>& v = adj[me];
        for(int i = 1; i <= n; ++i) {
            if(v[i] != 0 && !hasVisited[i]) {
                dfs(adj, hasVisited, i, n);
            }
        }
    }
}

int main() { _
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    int a, b;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= n; ++j) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    bool hasVisited[3000] = {0};

    hasVisited[1] = true;
    dfs(adj, hasVisited, 1, n);

    return 0;
}