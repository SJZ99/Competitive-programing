#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

typedef struct edge {
    int to;
    int flow;
    int capacity;
    int revIndex;
} Edge;

class Graph {
    int n;
    vector<vector<Edge>> adj;
    vector<int> level;
    
public:
    Graph(int v) : n(v) {
        adj = vector<vector<Edge>>(n, vector<Edge>());
        level = vector<int>(n, -1);
    }

    void addEdge(int from, int to, int capacity) {
        Edge a {to, 0, capacity, (int) adj[to].size()};
        Edge b {from, 0, 0, (int) adj[from].size()};

        adj[from].push_back(a);
        adj[to].push_back(b);
    }

    vector<vector<Edge>>& getEdges() { return adj; }

    bool findRoute(int s, int t);
    ll sendFlow(int curr, ll flow, vector<int>& visited, int t);
    ll Dinic(int s, int t);
};

bool Graph::findRoute(int s, int t) {
    for(int i = 0; i < n; ++i) {
        level[i] = -1;
    }

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        // cout << curr << " ";
        for(Edge& e : adj[curr]) {
            // haven't been visited and available
            if(level[e.to] < 0 && e.capacity > e.flow) {
                level[e.to] = level[curr] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] < 0 ? false : true;
}

ll Graph::sendFlow(int curr, ll flow, vector<int>& visited, int t) {
    if(curr == t) {
        return flow;
    }

    for(visited[curr]; visited[curr] < (int) adj[curr].size(); ++visited[curr]) {

        Edge& e = adj[curr][visited[curr]];
        if(level[e.to] == level[curr] + 1 && e.capacity > e.flow) {
            ll currFlow = min(flow, (ll) (e.capacity - e.flow));
            ll pathFlow = sendFlow(e.to, currFlow, visited, t);

            if(pathFlow > 0) {
                // cout << curr << " " << e.to << "\n";
                e.flow += pathFlow;
                adj[e.to][e.revIndex].flow -= pathFlow;
                return pathFlow;
            }
        }
    }

    return 0l;
}

ll Graph::Dinic(int s, int t) {
    if(s == t) return -1;

    ll total = 0;
    ll temp = 0;
    while(findRoute(s, t)) {
        vector<int> visited(n + 1, 0);

        while((temp = sendFlow(s, (int) 1e9, visited, t))) {
            total += temp;            
        }
    }

    return total;
}

int main() { _
    int n, m, k;
    cin >> n >> m >> k;

    Graph g(n + m + 2);
    
    int u, v;
    for(int i = 0; i < k; ++i) {
        cin >> u >> v;
        g.addEdge(u, v + n, 1);
    }

    for(int i = 1; i <= n; ++i) {
        g.addEdge(0, i, 1);
    }

    for(int i = n + 1; i <= n + m; ++i) {
        g.addEdge(i, n + m + 1, 1);
    }

    cout << "\n";
    ll res = g.Dinic(0, n + m + 1);
    cout << res << "\n";

    vector<vector<Edge>> adj = g.getEdges();
    for(int i = 1; i <= n; ++i) {
        for(Edge& e : adj[i]) {
            if(e.flow == 1) {
                cout << i << " " << e.to - n << "\n";
            }
        }
    }

    return 0;
}