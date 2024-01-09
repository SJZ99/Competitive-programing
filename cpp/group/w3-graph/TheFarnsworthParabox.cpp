#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main() { _
    
    int n, m;
    while(cin >> n >> m && n > 0 && m > 0) {

        vector<Edge> es;
        es.reserve(m);

        int u, v, w;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            es.push_back(Edge(u, v, w));
            es.push_back(Edge(v, u, -w));
        }

        vector<ll> dis(n + 1, INT_MAX);
        m = es.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                Edge e = es[j];
                dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
            }
        }

        bool negCycle = false;
        for(int j = 0; j < m; ++j) {
            Edge& e = es[j];
            if(dis[e.v] < dis[e.u] + e.w) {
                negCycle = true;
            }
        }

        if(negCycle) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}