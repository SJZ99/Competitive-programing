#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<ll, ll>;

struct Edge {
    int to;
    ll dis;

    Edge(int to, ll dis) : to(to), dis(dis) {
        ;
    }
};

int dire[4][2] {
    0, 1, 1, 0, -1, 0, 0, -1
};

set<point> ps;
vector<point> pv;
vector<int> indexOf;

bool isInSegment(point p, point a, point b) {
    if(a.X == b.X) { // vertical line
        return p.X == a.X && p.Y > min(a.Y, b.Y) && p.Y < max(a.Y, b.Y);
    } else if(a.Y == b.Y) { // horizon line
        return p.Y == a.Y && p.X > min(a.X, b.X) && p.X < max(a.X, b.X);
    } else { // should not happen, only check vertical or horizon line
        return true;
    }
}

bool isValidEdge(int i, int j) {
    // turning point has no farm, or no turning point
    point upper = {pv[j].X, pv[i].Y};
    bool ok1 = pv[i].X == pv[j].X || pv[i].Y == pv[j].Y || ps.find(upper) == ps.end();
    // check every farm
    for(point p : ps) {
        if(isInSegment(p, pv[i], upper) || isInSegment(p, upper, pv[j])) {
            ok1 = false;
            break;
        }
    }

    if(ok1) return true;

    point lower = {pv[i].X, pv[j].Y};
    bool ok2 = pv[i].X == pv[j].X || pv[i].Y == pv[j].Y || ps.find(lower) == ps.end();
    for(point p : ps) {
        if(isInSegment(p, pv[i], lower) || isInSegment(p, lower, pv[j])) {
            ok2 = false;
            break;
        }
    }

    if(ok2) return true;

    // no one of path available
    return false;
}

ll dist(int i, int j) {
    return abs(pv[i].X - pv[j].X) + abs(pv[i].Y - pv[j].Y);
}

typedef struct {
    bool operator()(pair<int, ll> a, pair<int, ll> b) {
        return a.second > b.second;
    }
} cmp;

vector<ll> dis;
vector<bool> closed;
vector<vector<Edge>> adj;

ll Dijkstra(int i, int j) {
    // cout << endl;

    for(int k = 0; k < closed.size(); ++k) {
        closed[k] = false;
        dis[k] = 1e10;
    }

    for(int k = 0; k < indexOf.size(); ++k) {
        if(indexOf[k] != i && indexOf[k] != j) {
            closed[indexOf[k]] = true;
        }
    }

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq;

    pq.push({i, 0});
    dis[i] = 0;

    while(!pq.empty()) {
        pair<int, ll> p = pq.top();
        pq.pop();
        // cout << pv[p.first].X << " " << pv[p.first].Y << " " << p.first << " " << j << endl;

        if(closed[p.first]) continue;

        if(p.first == j) {
            return dis[p.first];
        }

        auto adjs = adj[p.first];
        for(auto e : adjs) { 
            // cout << node.first << "\n";
            if(dis[p.first] + e.dis < dis[e.to]) {
                dis[e.to] = dis[p.first] + e.dis;
                pq.push({e.to, dis[e.to]});
            }
        }
        
        closed[p.first] = true;
    }

    return -1;
}

int main() { _
    int n;
    cin >> n;
    indexOf.resize(n);

    ll x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        indexOf[i] = pv.size();
        pv.push_back({x, y});
        ps.insert({x, y});
    }

    for(int i = 0; i < n; ++i) {
        x = pv[indexOf[i]].X;
        y = pv[indexOf[i]].Y;
        
        ll t1, t2;
        for(int i = 0; i < 4; ++i) {
            t1 = x + dire[i][0];
            t2 = y + dire[i][1];
            if(ps.find({t1, t2}) == ps.end()) {
                pv.push_back({t1, t2});
            }
        }
    }

    int len = pv.size();
    adj.resize(len);
    closed.resize(len, false);
    dis.resize(len, 1e10);

    for(int i = 0; i < len; ++i) {
        for(int j = i + 1; j < len; ++j) {
            if(isValidEdge(i, j)) {
                adj[i].push_back(Edge(j, dist(i, j)));
                adj[j].push_back(Edge(i, dist(i, j)));
            }
        }
    }
    
    ll ans = 0;
    ll cost = 0;
    for(int i = 0; i < n; ++i) {
        cost = Dijkstra(indexOf[i], indexOf[(i + 1) % n]);

        if(cost == -1) {
            ans = -1;
            break;
        } else {
            ans += cost;
        }
    }
    
    cout << ans << "\n";

    return 0;
}