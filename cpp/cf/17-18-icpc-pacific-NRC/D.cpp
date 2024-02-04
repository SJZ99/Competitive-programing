#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Edge {
    // not sure, broke, succes
    int flag;
    int to;
    int color;

    Edge(int to, int color) : to(to), color(color) {
        flag = 0;
    }
};
vector<int> res;
vector<vector<Edge>> adj;

bool dfs(int curr, int color, int pa) {
    bool isSuccess = true;
    for(Edge& e : adj[curr]) {
        if(e.to == pa) continue;
        if(e.flag == 1 || e.color == color) {
            isSuccess = false;
            break;
        } else if(e.flag == 0 && e.color != color) {
            bool next = dfs(e.to, e.color, curr);
            if(next) {
                e.flag = 2;
            } else {
                e.flag = 1;
            }
            isSuccess &= next;
        }

        if(!isSuccess) {
            break;
        }
    }

    return isSuccess;
}

int main() { _
    int n;
    cin >> n;

    adj.resize(n + 1);
    int u, v, c;
    for(int i = 1; i < n; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }

    for(int i = 1; i <= n; ++i) {
        if(dfs(i, -1, -1)) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}