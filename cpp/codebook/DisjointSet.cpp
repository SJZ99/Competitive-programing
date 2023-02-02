#include <bits/stdc++.h>
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
};
