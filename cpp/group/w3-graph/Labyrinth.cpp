#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
using vec = vector<int>;
using grid = vector<vec>;
struct step {
    int l, r;
    int x, y;

    step(int l, int r, int x, int y) : l(l), r(r), x(x), y(y) {}
};

int upDown[2] {
    1, -1
};

int main() { _
    int n, m;
    cin >> n >> m;
    cin.ignore();
    // cin.ignore();

    int x, y;
    cin >> x >> y;
    x--, y--;
    cin.ignore();
    // cin.ignore();

    int l, r;
    cin >> l >> r;
    cin.ignore();
    // cin.ignore();

    grid g(n, vec(m, 0));
    vector<vector<pair<int, int>>> best(n, vector<pair<int, int>>(m, {0, 0}));
    char c;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> c;
            if(c == '.') {
                g[i][j] = 0;
            } else {
                g[i][j] = -1;
            }
        }
        cin.ignore();
    }

    queue<step> q;
    q.push(step(l, r, x, y));

    int res = 0;
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        int cx = curr.x, cy = curr.y;

        // cout << cx << " " << cy << "\n";
        if(g[cx][cy] == 0) {
            res++;
        } else if(g[cx][cy] == 1 && curr.l <= best[cx][cy].first && curr.r <= best[cx][cy].second) {
            continue;
        }

        best[cx][cy] = {curr.l, curr.r};
        g[curr.x][curr.y] = 1;

        if(curr.l > 0) {
            int tx = curr.x;
            int ty = curr.y - 1;
            if(ty >= 0 && g[tx][ty] != -1) {
                q.push(step(curr.l - 1, curr.r, tx, ty));
            }
        }

        if(curr.r > 0) {
            int tx = curr.x;
            int ty = curr.y + 1;
            if(ty < m && g[tx][ty] != -1) {
                q.push(step(curr.l, curr.r - 1, tx, ty));
            }
        }

        for(int i = 0; i < 2; ++i) {
            int tx = curr.x + upDown[i];
            int ty = curr.y;
            if(tx >= 0 && tx < n && g[tx][ty] != -1) {
                q.push(step(curr.l, curr.r, tx, ty));
            }
        }
    }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << res << "\n";
    return 0;
}