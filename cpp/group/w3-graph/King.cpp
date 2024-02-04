#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Edge {
    int u, v, w;
};

int main() { _
    
    int n, m;
    string s;
    int a, b, c;
    while(cin >> n && n > 0) {
        cin >> m;
        vector<Edge> es(m);
        for(int i = 0; i < m; ++i) {
            cin >> a >> b >> s >> c;
            Edge e;
            if(s == "gt") {
                e.u = a + b;
                e.v = a - 1;
                e.w = -c - 1;
            } else {
                e.u = a - 1;
                e.v = a + b;
                e.w = c - 1;
            }
            es.push_back(e);
        }

        for(int i = 0; i <= n; ++i) {
            Edge e;
            e.u = n + 1;
            e.v = i;
            e.w = 0;
            es.push_back(e);
        }

        vector<int> dis(n + 2, 10000000);
        for(int i = 0; i <= n + 1; ++i) {
            for(int j = 0; j < es.size(); ++j) {
                Edge e = es[j];
                if(dis[e.v] > dis[e.u] + e.w) {
                    dis[e.v] = dis[e.u] + e.w;
                }
            }
        }

        bool hasSol = true;
        for(int j = 0; j < es.size(); ++j) {
            Edge e = es[j];
            if(dis[e.v] > dis[e.u] + e.w) {
                hasSol = false;
            }
        }
        
        if(hasSol) {
            cout << "lamentable kingdom\n";
        } else {
            cout << "successful conspiracy\n";
        }
    }

    return 0;
}