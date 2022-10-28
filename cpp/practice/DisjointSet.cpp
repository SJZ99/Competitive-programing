#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define debug(x) cout << x << "\n";
using namespace std;

typedef vector<vector<int>> matrix;

class DisjointSet {

private:
    int count = 0;
    int r, c;
    vector<int> rank;
    vector<int> root;
public:
    DisjointSet(matrix m): r(m.size()), c(m[0].size()) {
        rank.reserve(r * c);
        root.reserve(r * c);

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(m[i][j] == 1) {
                    root[i * c + j] = i * c + j;
                    rank[i * c + j] = 1;
                    ++count;
                } else {
                    root[i * c + j] = -1;
                }
            }
        }
    }

    int findRoot(int i) {
        if(i == root[i]) {
            return i;
        }
        // debug(i << " " << root[i])
        // path compression
        int currRoot = findRoot(root[i]);
        root[i] = currRoot;
        return currRoot;
    }

    void join(int i, int j) {
        if(i == j) return;
        if(i > root.size() - 1 || j > root.size() - 1 || i < 0 || j < 0) return;

        int iRoot = findRoot(i);
        int jRoot = findRoot(j);
        if(iRoot == jRoot) return;

        // join by rank or size (after path compression)
        if(rank[iRoot] > rank[jRoot]) {
            root[jRoot] = iRoot;
        } else if(rank[iRoot] < rank[jRoot]) {
            root[iRoot] = jRoot;
        } else {
            root[iRoot] = jRoot;
            ++rank[iRoot];
        }
        --count;
        show();
        debug(count)
    }

    int getCount() {
        return count;
    }

    void show() {
        cout << "root matrix: \n";
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cout << root[i * c + j] << " ";
            }
            cout << "\n";
        }
    }

};

int main() {

    matrix direction = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    matrix m = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    DisjointSet ds(m);
    ds.show();
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[0].size(); ++j) {

            if(m[i][j] == 1) {
                m[i][j] = 0;
                for(int k = 0; k < 4; ++k) {
                    int nextI = i + direction[k][0];
                    int nextJ = j + direction[k][1];

                    if(nextI >= 0 && nextI < m.size() &&
                        nextJ >= 0 && nextJ < m[0].size() &&
                        m[nextI][nextJ] == 1
                    ) {
                        ds.join(i * m[0].size() + j, nextI * m[0].size() + nextJ);
                    }
                }
            }
        }
    }

    ds.show();
    cout << ds.getCount();
    return 0;
}