#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int dire[4][2] {
    0, 1, 1, 0, -1, 0, 0, -1
};

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
                // cout << e.to << " ";
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

void dfs(int x, int y, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
 
    for(int k = 0; k < 4; ++k) {
        int tx = x + dire[k][0];
        int ty = y + dire[k][1];
 
        if(tx >= 0 && ty >= 0 && tx < n && ty < m) {
            if(grid[tx][ty] == 'L') {
                grid[tx][ty] = 'W';
                dfs(tx, ty, grid);
            }
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<vector<char>> grid(n, vector<char>(m, 0));
    vector<vector<int>> cnts(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != 'L') {
                continue;
            }

            int tx, ty;
            for(int k = 0; k < 4; ++k) {
                tx = i + dire[k][0];
                ty = j + dire[k][1];

                if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if(grid[tx][ty] == 'C') {
                        grid[tx][ty] = 'W';
                    }
                }
            }
        }
    }

    ll res = 0;

    int v = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'L') {
                dfs(i, j, grid);
                res++;
            }

            if(grid[i][j] == 'C') {
                cnts[i][j] = v++;
            }
        }
    }

    Graph g(v + 2);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'C' && (i + j) % 2 == 0) {
                int tx, ty;
                for(int k = 0; k < 4; ++k) {
                    tx = i + dire[k][0];
                    ty = j + dire[k][1];

                    if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if(grid[tx][ty] == 'C') {
                            g.addEdge(cnts[i][j], cnts[tx][ty], 1);
                            // cout << cnts[i][j] << " " << cnts[tx][ty] << endl;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'C') {
                if((i + j) % 2 == 0) {
                    g.addEdge(v, cnts[i][j], 1);
                    // cout << v << " " << cnts[i][j] << "\n";
                } else {
                    g.addEdge(cnts[i][j], v+1, 1);
                    // cout << cnts[i][j] << " " << v+1 << "\n";
                }
            }
        }
    }

    ll matching = g.Dinic(v, v + 1);

    res += v - matching;

    // cout << v << " " << matching << endl;
    cout << res << "\n";
        
    return 0;
}