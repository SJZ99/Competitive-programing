#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 1001
using namespace std;
using ll = long long int;

struct Edge {
    int to;
    int w;
};
vector<ll> dp;
ll dfs(vector<vector<Edge>>& to, int node) {
    if(dp[node] != 0) {
        return dp[node];
    }

    ll sum = 0;
    for(Edge& neibor : to[node]) {
        sum = max(dfs(to, neibor.to) + neibor.w, sum);
    }

    dp[node] = sum;
    return dp[node];
}

int main() { _
    int n, m;
    cin >> n >> m;
    dp = vector<ll>(n + 1, 0);

    vector<vector<Edge>> to(n + 1);
    vector<bool> in(n + 1, true);
    int a, b, c;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        to[a].push_back({b, c});
        in[b] == false;
    }

    ll maxx = 0;
    for(int i = 1; i < in.size(); ++i) {
        if(in[i]) {
            maxx = max(maxx, dfs(to, i));
        }
    }

    cout << maxx << "\n";

    return 0;
}