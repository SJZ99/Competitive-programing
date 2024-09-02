#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class DisjointSet {
    // parents
    vector<int> ps;
    vector<int> rank;
    vector<int> sz;
    int n;

public:
    DisjointSet(int n) : n(n) {
        ps.resize(n+1, -1);
        rank.resize(n+1, 1);
        sz.resize(n+1, 0);

        for(int i = 1; i <= n; ++i) {
            ps[i] = i;
        }
    }

    // return my parent
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
                sz[pa] += sz[pb] + 1;
                cout << pa << " " << pb << "\n";
            } else if(rank[pa] < rank[pb]){
                ps[pa] = pb;
                sz[pb] += sz[pa] + 1;
                cout << pb << " " << pa << "\n";
            } else {
                ps[pa] = pb;
                sz[pb] = sz[pa] + 1;
                rank[pb]++;
                cout << pb << " " << pa << "\n";
            }
        }
    }

    int maxSize() {
        int maxx = INT_MIN;
        for(int i = 1; i <= n; ++i) {
            maxx = max(maxx, sz[i]);
        }
        return maxx;
    }
};

int main(void) {
    int tc;
    cin >> tc;

    while(tc--) {
        int n, d;
        cin >> n >> d;

        DisjointSet dsu(n);

        int a, b;
        for(int i = 0; i < d; ++i) {
            cin >> a >> b;
            dsu.Union(a, b);
            cout << dsu.maxSize() << "\n";
        }
    }

    return 0;
}