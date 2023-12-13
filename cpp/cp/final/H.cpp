#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 100005
using namespace std;
int n, m, k;
bool pk[100005];
struct rode{
    int to, walk, car;
    int statue;
};
typedef struct {
    bool operator()(rode a, rode b) {
        if(a.statue == 1 && b.statue == a.statue)
            return a.walk > b.walk;
        else   
            return a.car > b.car;
    }
} cmp;

bool closed[N] = {0};
priority_queue<rode, vector<rode>, cmp> pq;
vector<long long int> dis(N, LLONG_MAX);
vector<rode> adj[N];

int main() { _
    cin >> n >> m >> k;
    for(int i=0, a = 0; i<k; i++){
        cin >> a;
        pk[a] = 1;
    }
    int a, b, c, d;
    for(int i = 0 ; i < m; ++i) {
        cin >> a >> b >> c >> d;
        rode rd;
        rd.car = c;
        rd.statue = 0;
        rd.to = b;
        rd.walk = d;
        adj[a].push_back(rd);
    }
    pq.push({1, 0 , 0, 0});
    dis[1] = 0;
    
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(closed[p.to]) continue;

        auto adjs = adj[p.to];
        for(auto node : adjs) { 
            rode rd;
            rd.to = node.to;
            rd.statue = 0;
            rd.car = node.car;
            rd.walk = node.walk;
            if(p.statue == 0){
                if(node.to == n){
                    continue;
                }
                if(dis[p.to] + node.car < dis[node.to]) {
                    dis[node.to] = dis[p.to] + node.car;
                    if(pk[p.to]){
                        pq.push(rd);
                        rd.statue = 1;
                        pq.emplace(rd);
                    }
                }
            } else {
                if(dis[p.to] + node.walk < dis[node.to]) {
                    dis[node.to] = dis[p.to] + node.walk;
                    rd.statue = 1;
                    pq.emplace(rd);
                }
            }
        }
        closed[p.to] = true;
    }

    for(int i = 1; i <= n; ++i) {
        cout << dis[i];
        cout << " ";
    }
    cout << dis[n] << '\n';
    return 0;
}