#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 100005

using namespace std;
using ll = long long int;

typedef pair<int, int> CostTo;

vector<vector<CostTo>> adj(N, vector<CostTo>());
bool visited[N] = {0};
priority_queue<CostTo, vector<CostTo>, greater<CostTo>> pq;

ll prim(int n) {
    pq.push({0, 1});

    long long int total = 0;
    int cnt = 0;
    while(!pq.empty()) {
        int curr = pq.top().second; 

        if(visited[curr]) { 
            pq.pop();
            continue;
        }

        total += pq.top().first; pq.pop();
        visited[curr] = true;
        cnt++;

        for(CostTo ct : adj[curr]) {
            if(!visited[ct.second]) {
                pq.push({ct.first, ct.second});
            }
        }

        if(cnt == n) {
            break;
        }
    }

    if(cnt == n) {
        return total;
    } else {
        return -1;
    }
}

int main() { _
    int n, m;
    int u, v, w;
    
    cin >> n >> m;

    
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    pq.push({0, 1});

    long long int total = 0;
    int cnt = 0;
    while(!pq.empty()) {
        int curr = pq.top().second; 

        if(visited[curr]) { 
            pq.pop();
            continue;
        }

        total += pq.top().first; pq.pop();
        visited[curr] = true;
        cnt++;

        for(CostTo ct : adj[curr]) {
            if(!visited[ct.second]) {
                pq.push({ct.first, ct.second});
            }
        }

        if(cnt == n) {
            break;
        }
    }

    if(cnt == n) {
        cout << total << "\n";
    } else cout << "-1\n";

    return 0;
}