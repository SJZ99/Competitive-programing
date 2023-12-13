#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 100005
using namespace std;
using ll = long long int;

typedef struct {
    bool operator()(pair<int, long long int> a, pair<int, long long int> b) {
        return a.second > b.second;
    }
} cmp;

bool closed[N] = {0};
priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> pq;
vector<long long int> dis(N, LLONG_MAX);
vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>());

void Dijkstra() {
    pq.push({1, 0});
    dis[1] = 0;
    
    while(!pq.empty()) {
        pair<int, long long int> p = pq.top();
        pq.pop();

        if(closed[p.first]) continue;

        auto adjs = adj[p.first];
        for(auto node : adjs) { 
            // cout << node.first << "\n";
            if(dis[p.first] + node.second < dis[node.first]) {
                dis[node.first] = dis[p.first] + node.second;
                pq.push({node.first, dis[node.first]});
            }
        }
        
        closed[p.first] = true;
    }
}

int main() { _
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for(int i = 0 ; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    pq.push({1, 0});
    dis[1] = 0;
    
    while(!pq.empty()) {
        pair<int, long long int> p = pq.top();
        pq.pop();

        if(closed[p.first]) continue;

        auto adjs = adj[p.first];
        for(auto node : adjs) { 
            // cout << node.first << "\n";
            if(dis[p.first] + node.second < dis[node.first]) {
                dis[node.first] = dis[p.first] + node.second;
                pq.push({node.first, dis[node.first]});
            }
        }
        
        closed[p.first] = true;
    }

    for(int i = 1; i <= n; ++i) {
        cout << dis[i];
        cout << " ";
    }

    return 0;
}