#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int n, m;
int n2, m2;
vector<vector<bool>> vis;

int dire[8][2] = {
    0, 1, 1, 0, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1
};

void dfs(int r, int c, vector<vector<char>>& grid) {
    grid[r][c] = '+';
    vis[r][c] = true;
    for(int i = 0; i < 8; ++i) {
        int tr = r + dire[i][0];
        int tc = c + dire[i][1];
        if(tr < n2 && tc < m2 && tr >= 0 && tc >= 0 && grid[tr][tc] == '.' && !vis[tr][tc]) {
            dfs(tr, tc, grid);
        }
    }
}

int main() { _
    cin >> n >> m;
    n2 = 2 * n - 1;
    m2 = 2 * m - 1;

    vector<vector<char>> grid(2 * n, vector<char>(2 * m));
    vis = vector<vector<bool>>(2 * n, vector<bool>(2 * m, false));
    for(int i = 0; i < n; ++i) {
        int r = i * 2;
        for(int j = 0; j < m; ++j) {
            int c = j * 2;
            cin >> grid[r][c];
            if(j > 0) {
                if(grid[r][c - 2] == '.' || grid[r][c] == '.') {
                    grid[r][c - 1] = '.';
                } else if(grid[r][c - 2] != grid[r][c]) {
                    grid[r][c - 1] = '-';
                } else {
                    grid[r][c - 1] = '.';
                }
            }
        }

        if(i > 0) {
            for(int j = 0; j < m2; ++j) {
                if(j % 2 == 0) {
                    if(grid[r - 2][j] == '.' || grid[r][j] == '.') {
                        grid[r - 1][j] = '.';
                    } else if(grid[r - 2][j] != grid[r][j]) {
                        grid[r - 1][j] = '|';
                    } else {
                        grid[r - 1][j] = grid[r][j];
                    }
                } else {
                    if(grid[r - 2][j - 1] == grid[r][j + 1] && grid[r][j + 1] == '\\') {
                        grid[r - 1][j] = '\\';
                    } else if(grid[r - 2][j + 1] == grid[r][j - 1] && grid[r][j - 1] == '/') {
                        grid[r - 1][j] = '/';
                    } else {
                        grid[r - 1][j] = '.';
                    }
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n2; ++i) {
        for(int j = 0; j < m2; ++j) {
            if(grid[i][j] == '.') {
                res++;
                // cout << i << " " << j << "\n";
                dfs(i, j, grid);

                for(int k = 0; k < n2; ++k) {
                    for(int l = 0; l < m2; ++l) {
                        cout << grid[k][l];
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }
    }
    cout << res << "\n";
    return 0;
}