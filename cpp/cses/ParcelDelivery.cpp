#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
using p = pair<int, int>;

struct Edge {
    int to;
    int rev;
    ll flow;
    ll cost;
};

pair<int, int> MCMF(vector<vector<Edge>> adj, int s, int t, int k) {
    int n = adj.size();
    ll totalFlow = 0, totalCost = 0;

    while(true) {

        vector<ll> dis(n, INT_MAX);
        vector<bool> inQueue(n, false);
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        inQueue[s] = true;

        vector<p> from(n, {-1, -1});

        // find route
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            inQueue[curr] = false;

            for(int i = 0; i < (int) adj[curr].size(); ++i) {
                Edge& e = adj[curr][i];
                if(e.flow > 0 && dis[e.to] > dis[curr] + e.cost) {
                    dis[e.to] = dis[curr] + e.cost;
                    from[e.to] = {curr, i};

                    if(!inQueue[e.to]) {
                        q.push(e.to);
                        inQueue[e.to] = true;
                    }
                }
            }
        }

        if(dis[t] >= INT_MAX) break;

        ll flow = INT_MAX;
        for(int i = t; i != s; i = from[i].first) {
            int pa = from[i].first;
            int j = from[i].second;
            flow = min(flow, adj[pa][j].flow);
        }

        if(totalFlow + flow > k) {
            totalCost += (k - totalFlow) * dis[t];
            totalFlow = k;
            break;
        } else {
            totalFlow += flow, totalCost += flow * dis[t];
            if(totalFlow == k) {
                break;
            }
        }

        for(int i = t; i != s; i = from[i].first) {
            int pa = from[i].first;
            int j = from[i].second;
            Edge& e = adj[pa][j];
            e.flow -= flow;
            adj[e.to][e.rev].flow += flow;
        }
    }
    return {totalFlow, totalCost};
}

int main() { _
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n);

    int u, v, f, c;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> f >> c;
        u--, v--;
        Edge a {v, (int) adj[v].size(), f, c};
        Edge b {u, (int) adj[u].size(), 0, -c};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    p res = MCMF(adj, 0, n - 1, k);

    if(res.first < k) cout << "-1\n";
    else cout << res.second << "\n";

    return 0;
}