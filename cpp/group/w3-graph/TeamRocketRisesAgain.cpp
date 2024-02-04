#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define N 200001

using namespace std;
using ll = long long int;

vector<ll> dis(N, 1e16);

struct Cmp {
    bool operator() (const pair<int, ll>& a, const pair<int, ll>& b) {
        return a.second > b.second;
    }
};

vector<vector<pair<int, ll>>> adj;

void Dijkstra(int s) {
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, Cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(dis[p.first] < p.second) continue;

        auto adjs = adj[p.first];
        for(auto node : adjs) { 
            if(dis[p.first] + node.second < dis[node.first]) {
                dis[node.first] = dis[p.first] + node.second;
                pq.push({node.first, dis[node.first]});
            }
        }
    }
}

int main() { _
    int n, m, s;
    cin >> n >> m >> s;

    adj.resize(n + 1);

    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if(adj[s].size() == 0) {
        cout << "0\n";
        return 0;
    }

    Dijkstra(s);

    vector<vector<int>> g(n + 1);
    vector<int> in(n + 2, 0);

    // create graph
    for(int i = 1; i <= n; ++i) {
        for(auto p : adj[i]) {
            int to = p.first;
            ll d = p.second;
            if(dis[i] + d == dis[to]) {
                g[i].push_back(to);
                in[to]++;
            }
        }
    }

    vector<int> size(n + 2, 0);
    vector<int> pre(n + 2);
    for(int i = 0; i < pre.size(); ++i) pre[i] = i;

    vector<int> pa(n + 2, 0);
    
    queue<int> nodes;
    nodes.push(s);
    while(!nodes.empty()) {
        int curr = nodes.front(); nodes.pop();

        // determine pa
        if(pre[curr] != -1 && pre[curr] != s) pa[curr] = pre[curr];
        else pa[curr] = curr;
        size[pa[curr]]++;

        for(int neigh : g[curr]) {
            if(pre[neigh] == neigh) pre[neigh] = pa[curr];
            else if(pre[neigh] != pa[curr]) pre[neigh] = -1;

            // topological
            in[neigh]--;
            if(in[neigh] == 0) {
                nodes.push(neigh);
            }
        }
    }

    int maxx = 0;
    for(int i = 0; i <= n; ++i) {
        if(i != s) {
            maxx = max(maxx, size[i]);
        }
    }

    cout << maxx << "\n";

    return 0;
}