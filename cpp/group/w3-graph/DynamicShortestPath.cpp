#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define INF (ll) 1e18

using namespace std;
using ll = long long int;
int n;

struct Edge {
    int v;
    ll w;
    Edge(int v, ll w) : v(v), w(w) {
        ;
    }

    inline bool operator < (const Edge& e) const {
        return w > e.w;
    }
};

vector<Edge*> edges;
vector<vector<Edge*>> adj;

ll dis[100005];
priority_queue<Edge> pq;

inline void Dijkstra1() {
    memset(dis, 0x3f, sizeof(ll) * (n + 2));

    pq.push({1, 0});
    dis[1] = 0;
    
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        auto adjs = adj[p.v];
        for(auto e : adjs) { 
            if(dis[p.v] + e->w < dis[e->v]) {
                dis[e->v] = dis[p.v] + e->w;
                // cout << e->v << " " << dis[e->v] << endl;
                pq.push(Edge(e->v, dis[e->v]));
            }
        }
    }
}

ll d[100005];
vector<queue<int>> q(100005);

inline void Dijkstra2(int k) {

    memset(d, 0x3f, (n + 2) * sizeof(ll));

    ll maxx = 3;

    q[0].push(1);
    d[1] = 0;
    
    for(int i = 0; i <= maxx; ++i) {
        while(!q[i].empty()) {
            int p = q[i].front();
            q[i].pop();

            if(d[p] < i) continue;

            auto adjs = adj[p];
            for(auto e : adjs) {
                ll potential = e->w + dis[p] - dis[e->v] + d[p];
                if(potential < d[e->v]) {
                    d[e->v] = potential;
                    if(potential <= min(k, n)) {
                        q[potential].push(e->v);
                        maxx = max(maxx, potential);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        dis[i] = min((ll) INF, d[i] + dis[i]);
    }
}

int main() {_

    int m, q;
    cin >> n >> m >> q;

    adj.resize(n + 1);
    int u, v, w;
    edges.reserve(m + 3);
    edges.push_back(nullptr);

    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        Edge *e = new Edge(v, w);
        edges.push_back(e);
        adj[u].push_back(e);
    }

    Dijkstra1();
    // for(int i = 1; i <= n; ++i) {
    //     cout << dis[i] << " ";
    // } cout << "\n";

    int a, b;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        if(a == 1) {

            if(dis[b] >= INF) {
                cout << "-1\n";
            } else {
                cout << dis[b] << "\n";
            }
        } else {
            for(int j = 0; j < b; ++j) {
                cin >> a;
                edges[a]->w++;
            }
            Dijkstra2(b);
        }
    }

    return 0;
}