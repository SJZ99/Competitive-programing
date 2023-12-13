#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef struct {
    int u, v;
    long long int w;
} Edge;

vector<Edge> edges(10005);

bool bellman(int n) {
    vector<int> dis(1005, INT_MAX);
    for(int i = 1; i <= n; ++i) {
        for(Edge e : edges) {
            if(dis[e.v] > dis[e.u] + e.w) {
                dis[e.v] = dis[e.u] + e.w;

                if(i == n) {
                    return true;
                }
            }
        } 
    }
    return false;
}

int main() { _
    int n, m;
    cin >> n >> m;

    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    if(bellman(n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}