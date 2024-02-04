#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define de cout << "t\n";
#define N 100005

using namespace std;

class DisjointSet {
    // parents
    vector<int> ps;
    vector<int> rank;

public:
    int group;

    DisjointSet(int n) : group(n) {
        ps.resize(n + 3, -1);
        rank.resize(n + 3, 1);

        for(int i = 0; i < n + 3; ++i) {
            ps[i] = i;
        }
    }

    // return my parent
    int find(int me) {
        if(ps[me] == me) return me;
        return ps[me] = find(ps[me]);
    }

    bool Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa != pb) {
            if(rank[pa] > rank[pb]) {
                ps[pb] = pa;
            } else if(rank[pa] < rank[pb]){
                ps[pa] = pb;
            } else {
                ps[pa] = pb;
                rank[pb]++;
            }
            group--;
            return true;
        }
        return false;
    }
};

typedef struct {
    int u, v, w;
} Edge;

bool cmp(Edge& a, Edge& b) {
    return a.w < b.w;
}

vector<Edge> edges(N);

int main() { 
    int n, m;
    cin >> n >> m;
    edges.clear();
    DisjointSet dsu = DisjointSet(n);

    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back(Edge {u, v, w});
    }
    
    sort(edges.begin(), edges.end(), cmp);

    long long int total = 0;
    for(int i = 0; i < m; ++i) {
        auto curr = edges[i];
        if(dsu.Union(curr.u, curr.v)) {
            total += curr.w;
        }
    }

    if(dsu.group == 1) cout << total << "\n";
    else cout << "-1\n";

    return 0;
}
