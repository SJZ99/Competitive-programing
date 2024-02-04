#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

using pii = pair<int, int>;
struct Edge {
    int to;
    pii range;
};

int n, m, k;
int s, t;
vector<vector<Edge>> adj;
vector<bool> vis;

void dfs(int curr, int a) {

    vis[curr] = true;
    if(curr == t) {
        return;
    }

    for(Edge& e : adj[curr]) {
        if(a <= e.range.second && a >= e.range.first && !vis[e.to]) 
            dfs(e.to, a);
    }
}

bool isOk(int a) {
    for(int i = 1; i <= n; ++i) {
        vis[i] = false;
    }
    dfs(s, a);
    return vis[t];
}

int main() { _
    cin >> n >> m >> k;
    cin >> s >> t;

    adj.resize(n + 1);
    vis.resize(n + 1);

    int u, v, a, b;
    set<int> points;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> a >> b;
        pii pa;
        pa.first = a;
        pa.second = b;
        adj[u].push_back({v, pa});

        points.insert(a);
        points.insert(b + 1);
    }

    int last = 0;
    bool lastOk = false;
    ll res = 0;
    for(int p : points) {
        if(lastOk) {
            res += p - last;
        }
        lastOk = isOk(p);
        // cout << p << " " << lastOk << "\n";
        last = p;
    }

    cout << res << "\n";
    return 0;
}