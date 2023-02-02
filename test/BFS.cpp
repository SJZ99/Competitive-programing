#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;

typedef pair<int, int> Node;
typedef vector<vector<int>> Matrix;

Matrix maze {
    {0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 0},
};

// top, down, left, right
vector<vector<int>> direction {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int main() { _
    int n = maze.size();
    Matrix mem (n, vector<int>(n, -1));
    queue<Node> q;

    // start
    q.push({0, 0});
    mem[0][0] = 0;

    while(!q.empty()) {
        Node curr = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int tx = curr.X + direction[i][0];
            int ty = curr.Y + direction[i][1];

            if(tx >= 0 && tx < n && ty >= 0 && ty < n && maze[tx][ty] != 1 && mem[tx][ty] == -1) {
                q.push({tx, ty});
                mem[tx][ty] = mem[curr.X][curr.Y] + 1;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << mem[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
