#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

struct Edge {
    int to;
    int open;
};

int main() { _
    int n, m, s, k;
    cin >> n >> m >> s >> k;
    s--, k--;

    vector<vector<Edge>> adj(n);
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--, w--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<queue<int>> q(7);

    for(Edge& e : adj[s]) {
        q[e.open].push(e.to);
    }

    int today = 0;
    int days = 0;
    vector<bool> vis(n, false);
    vis[s] = true;
    while(days < m * 7 + 3) {
        days++;
        bool isFin = false;
        queue<int> tq;
        
        // cout << "today: " << today << "\n";
        while(!q[today].empty()) {
            int nei = q[today].front();
            // if(vis[nei]) {
            //     q[today].pop();
            //     continue;
            // }
            vis[nei] = true;
            // cout << nei << " ";
            q[today].pop();

            if(nei == k) {
                isFin = true;
                break;
            }

            for(Edge& e : adj[nei]) {
                if(vis[e.to]) {
                    continue;
                }
                if(e.open == today) {
                    tq.push(e.to);
                } else {
                    q[e.open].push(e.to);
                }
            }
            adj[nei] = vector<Edge>();
        }
        // cout << "\n";

        q[today] = tq;

        if(isFin) break;
        today++;
        today %= 7;
    }

    cout << days << "\n";

    return 0;
}