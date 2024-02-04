#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
using pii = pair<int, int>;

struct Edge {
    int to;
    pii range;
};

struct Node {
    int to, t;
    pii range;
};

pii And(const pii& a, const pii& b) {
    pii p;
    p.first = max(a.first, b.first);
    p.second = min(a.second, b.second);
    return p;
}
struct hashFunction { 
  size_t operator() (const pair<int, int> &x) const { 
    return x.first ^ x.second; 
  } 
}; 

int main() { _
    int n, m, k;
    int s, t;

    cin >> n >> m >> k;
    cin >> s >> t;

    vector<vector<Edge>> es(n + 1);
    vector<pii> rs;
    unordered_map<int, set<pii, hashFunction>> vis;

    int u, v, a, b;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> a >> b;
        Edge e;
        e.to = v;
        e.range = {a, b};
        es[u].push_back(e);
    }

    queue<Node> q;

    pii all = {1, k};
    Node init;
    init.t = 0;
    init.range = all;
    init.to = s;
    q.push(init);

    while(!q.empty()) {
        Node curr = q.front();
        // cout << curr.to << "\n";
        q.pop();

        if(curr.to == t) {
            rs.push_back(curr.range);
            continue;
        }

        if(curr.t == n - 1) {
            continue;
        }

        for(Edge& e : es[curr.to]) {
            int nei = e.to;
            pii p = e.range;
            pii res = And(p, curr.range);
            // cout << nei << " ";
            // cout << res.first << " " << res.second << "\n";
            if(res.first <= res.second && vis[nei].find(res) == vis[nei].end()) {
                vis[nei].insert(res);
                Node newNode = {nei, curr.t + 1, res};
                q.push(newNode);
            } 
        }
        // cout << "\n";
    }

    if(rs.size() == 0) {
        cout << "0\n";
        return 0;
    }

    sort(rs.begin(), rs.end());
    // for(pii& p : rs) {
    //     cout << p.first << " " << p.second << "\n";
    // }
    vector<pii> rs2;
    rs2.push_back(rs[0]);
    for(int i = 1; i < rs.size(); ++i) {
        if(rs2.back().second >= rs[i].first) {
            rs2.back().second = max(rs[i].second, rs2.back().second);
        } else {
            rs2.push_back(rs[i]);
        }
    }

    ll ans = 0;
    for(pii& p : rs2) {
        // cout << p.first << " " << p.second << "\n";
        ans += p.second - p.first + 1;
    }

    cout << ans << "\n";
    return 0;
}