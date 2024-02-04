#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MOD ((int) 1e9 + 7)
using namespace std;

// in times, node
vector<vector<int>> from(100001, vector<int>());
vector<vector<int>> to(100001, vector<int>());
vector<long long int> dp(100001, 0);
bool isVisited[100001];

int main() { _
    int n, m;
    cin >> n >> m;

    int u, v;

    vector<int> in(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        from[i].reserve(500);
        to[i].reserve(500);
    }

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        in[v]++;
        from[v].push_back(u);
        to[u].push_back(v);
    }

    queue<int> q;

    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto curr = q.front(); q.pop();

        for(int nei : to[curr]) {
            in[nei]--;
            dp[nei] = (dp[nei] + dp[curr]) % MOD;

            if(in[nei] == 0) {
                q.push(nei);
            }
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}