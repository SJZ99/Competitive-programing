#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

class DisjointSet {
    // parents
    vector<int> ps;
    vector<int> rank;

public:
    DisjointSet(int n) {
        ps.resize(n + 1, -1);
        rank.resize(n + 1, 1);

        for(int i = 0; i <= n; ++i) {
            ps[i] = i;
        }
    }

    int find(int me) {
        if(ps[me] == me) return me;
        return ps[me] = find(ps[me]);
    }

    void Union(int a, int b) {
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
        }
    }
    
    bool connected(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        return pa == pb;
    }
};

int main() { _
    int n, m, q;
    int x, y;

    cin >> n >> m >> q;
    DisjointSet dsu = DisjointSet(n);

    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        dsu.Union(x, y);
    }

    for(int i = 0; i < q; ++i) {
        cin >> x >> y;
        if(dsu.connected(x, y)) {
            cout << "My friends!\n";
        } else cout << "Mirudayo\n";
    }

    return 0;
}