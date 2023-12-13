#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

class DisjointSet {
    // parents
    vector<int> ps;
    vector<int> rank;

public:
    DisjointSet(int n) {
        ps.resize(n, -1);
        rank.resize(n, 1);

        for(int i = 0; i < n; ++i) {
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
            } else if(rank[pa] < rank[pb]){
                ps[pa] = pb;
            } else {
                ps[pa] = pb;
                rank[pb]++;
            }
        }
    }

    bool isConnect(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == -1 && pb == -1) return true;
        if(pa == pb) return true;
        else return false;
    }
};

int main() { _
    int n;
    cin >> n;
    char c;
    int a, b;

    DisjointSet ds((int)1e6 + 1);

    vector<pair<int, int>> ene;
    while(n--) {
        cin >> c >> a >> b;
        if(c == 'F') {
            ds.Union(a, b);
        } else {
            ene.push_back({a, b});
        }
    }

    for(auto p : ene) {
        if(ds.isConnect(p.first, p.second)) {
            cout << "Bob\n";
            return 0;
        }
    }

    cout << "Alice\n";

    return 0;
}