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
    int cnt = 1;
    while(cin >> n >> m && n > 0 && m > 0) {
        vector<Edge> es;
        es.reserve(m);

        int u, v, w;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            es.push_back(Edge(u, v, w));
        }

        int f, t, flow;
        cin >> f >> t >> flow;
        vector<int> maxx(n + 1, 0);
        maxx[f] = flow + 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                Edge e = es[j];
                maxx[e.v] = max(maxx[e.v], min(maxx[e.u], e.w));
                maxx[e.u] = max(maxx[e.u], min(maxx[e.v], e.w));
            }
        }

        // for(int i = 1; i <= n; ++i) {
        //     cout << maxx[i] << " ";
        // } cout << "\n";

        cout << "Scenario #" << cnt << "\n";
        maxx[t]--;
        // cout << maxx[t] << "\n";
        cout << "Minimum Number of Trips = " << ((flow / maxx[t]) + ((flow % maxx[t]) != 0)) << "\n\n";
        cnt++;
    }
    return 0;
}