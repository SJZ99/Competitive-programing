#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int root = 1;
int n = 6;
vector<vector<int>> edges {
    {2, 3},
    {3, 5},
    {4, 6},
    {1, 3},
    {1, 4}
};
vector<int> dist;

void dfs(vector<vector<int>>& adj, int me, int curr, int parent) {
    // operation
    dist[me] = curr;

    // go to next
    for(int i = 1; i <= n; ++i) {
        if(adj[me][i] == 1 && i != parent) {
            dfs(adj, i, curr + 1, me);
        }
    }

}

int main() { _
    dist.resize(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for(vector<int> edge : edges) {
        adj[edge[0]][edge[1]] = 1;
        adj[edge[1]][edge[0]] = 1;
    }

    dfs(adj, root, 0, -1);

    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}