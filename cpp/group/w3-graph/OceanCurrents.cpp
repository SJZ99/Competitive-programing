#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

using vec = vector<int>;
using matrix = vector<vec>;

struct step {
    int cost, r, c;
    step(int cost, int r, int c) : cost(cost), r(r), c(c) {}
};

int dire[8][2] {
    -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1
};

int main() { _
    int n, m;
    cin >> n >> m;
    cin.ignore();
    
    matrix grid(n, vec(m, 0));
    char ch;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> ch;
            grid[i][j] = ch - '0';
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        sr--, sc--, dr--, dc--;

        matrix best(n, vec(m, INT_MAX));
        deque<step> q;
        q.push_front(step(0, sr, sc));

        while(!q.empty()) {
            auto curr = q.front(); q.pop_front();
            int cr = curr.r, cc = curr.c;
            // cout << curr.cost << " ";
            if(curr.cost >= best[cr][cc]) {
                continue;
            }

            best[cr][cc] = curr.cost;

            if(cr == dr && cc == dc) {
                break;
            }

            for(int i = 0; i < 8; ++i) {
                int tr = cr + dire[i][0];
                int tc = cc + dire[i][1];
                if(tr >= 0 && tr < n && tc >= 0 && tc < m) {
                    int cost = curr.cost + (grid[cr][cc] != i);
                    if(cost < best[tr][tc]) {
                        if(grid[cr][cc] == i) {
                            q.push_front(step(cost, tr, tc));
                        } else {
                            q.push_back(step(cost, tr, tc));
                        }
                    }
                }
            }            
        }

        cout << best[dr][dc] << "\n";
    }

    return 0;
}