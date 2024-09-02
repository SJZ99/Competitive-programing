#pragma GCC optimize("O3", "unroll-loops")

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

pair<int, int> MCMF(vector<vector<Edge>>& adj, int s, int t) {
    
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

        totalFlow += flow, totalCost += flow * dis[t];

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
    int n;
    cin >> n;

    int c;
    vector<vector<Edge>> es(2 * n + 2);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> c;
            Edge a {j + n, (int) es[j + n].size(), 1, c};
            Edge b {i, (int) es[i].size(), 0, -c};
            es[i].push_back(a);
            es[j + n].push_back(b);
        }
    }

    int s = 2 * n, t = 2 * n + 1;

    for(int i = 0; i < n; ++i) {
        Edge a {i, (int) es[i].size(), 1, 0};
        Edge b {s, (int) es[s].size(), 0, 0};
        es[s].push_back(a);
        es[i].push_back(b);
    }

    for(int i = 0; i < n; ++i) {
        Edge a {t, (int) es[t].size(), 1, 0};
        Edge b {i + n, (int) es[i + n].size(), 0, 0};
        es[i + n].push_back(a);
        es[t].push_back(b);
    }

    cout << MCMF(es, s, t).second << "\n";

    for(int i = 0; i < n; ++i) {
        for(Edge& e : es[i]) {
            if(e.flow == 0 && e.cost > 0) {
                cout << i + 1 << " " << e.to - n + 1 << "\n";
            }
        }
    }

    return 0;
}