#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define X first
#define Y second
#define t cout << "t\n";

using namespace std;

typedef pair<int, int> Point;


vector<Point> nodes;

int dis(int i, int j) {
    return max(abs(nodes[i].X - nodes[j].X), abs(nodes[i].Y - nodes[j].Y));
}

int main() { _
    int x, y;
    
    Point root;
    while(cin >> x >> y) {
        nodes.clear();
        nodes.push_back({-1, -1});
        char c;
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                cin >> c;
                if(c == 'L') {
                    root = {i, j};
                }

                if(c == '#') {
                    nodes.push_back({i, j});
                }
            }
        }
        nodes[0] = root;
        
        int n = nodes.size();
        if(n == 1) {
            cout << 0 << "\n";
            continue;
        }
        
        int finalState = (1 << (n - 1)) - 1;
        unsigned short dp[n + 1][finalState + 1] = {0};

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= finalState; ++j) {
                dp[i][j] = 1000;
            }
        }
        
        for(int i = 1; i < n; ++i) {
            dp[i][(1 << (i - 1))] = dis(0, i);
            // cout << dis(0, i) << " ";
        }
        // cout << "\n";
        
        for(int i = 0; i <= finalState; ++i) {
            for(int j = 1; j < n; ++j) {
                // not in collection
                if(!((1 << (j - 1)) & i)) {
                    continue;
                }

                for(int k = 1; k < n; ++k) {
                    // in collection
                    if(!((1 << (k - 1)) & (i - (1 << (j - 1))))) {
                        continue;
                    }
                    // cout << i << " " << j << " " << k << "\n";
                    dp[j][i] = min(dp[k][i - (1 << (j - 1))] + dis(k, j), (int)dp[j][i]);
                }
            }
        }
        
        // for(int i = 1; i < n; ++i) {
        //     for(int j = 1; j <= finalState; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int minn = INT_MAX;
        for(int i = 1; i < n; ++i) {
            minn = min(dp[i][finalState] + dis(0, i), minn);
        }
        cout << minn << "\n";
    }

    return 0;
}