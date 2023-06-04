#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

using llu = unsigned long long int;

vector<vector<llu>> dis(501, vector<llu>(501, LONG_LONG_MAX));

void floyd(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                dis[j][k] = min(dis[j][k], dis[i][j] + dis[i][k]);
            }
        }
    }
}

int main() { _
    int n, m, q;
    cin >> n >> m >> q;

    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        dis[u][v] = min((llu)w, dis[u][v]);
        dis[v][u] = min((llu)w, dis[v][u]);
    }

    for(int i = 0; i <= n; ++i) {
        dis[i][i] = min(dis[i][i], (llu)0);
    }

    floyd(n);

    int a, b;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        if(dis[a][b] >= LONG_LONG_MAX) {
            cout << "-1\n";
        } else {
            cout << dis[a][b] << "\n";
        }
        
    }

    return 0;
}