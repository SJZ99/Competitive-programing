#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 100005
using namespace std;

vector<int> in(N, 0);
vector<list<int>> to(N, list<int>());
vector<int> res;
bool visited[N];
int main() { _
    int n, m;
    cin >> n >> m;

    to.clear();
    res.reserve(N);
    int u, v;
    while(m--) {
        cin >> u >> v;
        to[u].push_back(v);
        in[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        // if(visited[curr]) continue;
        res.push_back(curr);
        // visited[curr] = true;
        
        for(int neighbor : to[curr]) {
            in[neighbor]--;
            // && !visited[neighbor]
            if(in[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if(res.size() == n) {
        for(int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    

    return 0;
}