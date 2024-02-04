#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef struct {
    long long int u, w;
} Edge;

vector<vector<Edge>> edges(1003, vector<Edge>());

// queue-optimization
vector<long long int> dis(1005, INT_MAX);
queue<int> q;
bool inQueue[1005] = {0};
int times[1005] = {0};

bool bellmanTest_opt(vector<vector<Edge>>& edges, int n) {
    q.push(1);
    dis[1] = 0;
    while(!q.empty()) {
        int curr = q.front();
        // cout << curr - 1 << " ";
        q.pop();
        inQueue[curr] = false;

        times[curr]++;

        if(times[curr] >= n) {
            // cout << curr << "\n";
            // for(int i = 0; i <= n; ++i) {
            //     cout << dis[i] << " ";
            // }
            // cout << "\n";
            return true;
        }

        for(Edge e : edges[curr]) {
            if(dis[e.u] > (dis[curr] + e.w)) {
                dis[e.u] = dis[curr] + e.w;

                if(!inQueue[e.u]) {
                    // cout << curr - 1 << " " << e.u - 1 << "\n";
                    q.push(e.u);
                    inQueue[e.u] = true;
                }
            }
        }
    }
    return false;
}

int main() { _
    int n, m;
    cin >> n >> m;

    long long int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    if(bellmanTest_opt(edges, n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}