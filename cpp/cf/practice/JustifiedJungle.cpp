#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

vector<int> s;
vector<int> d;

int dfs(int curr, int from, vector<vector<int>>& adj) {
    
    if(s[curr] != -1) {
        return s[curr];
    }

    int curSize = 1;
    for(int nei : adj[curr]) {
        if(nei != from) {
            curSize += dfs(nei, curr, adj);
        }
    }

    s[curr] = curSize;
    return s[curr];
}

void traverse(int curr, int from, vector<vector<int>>& adj) {

    int n = s[curr];
    int rt = sqrt(n);
    for(int i = 1; i <= rt; ++i) {
        if(s[curr] % i == 0) {
            d[i]++;

            if(i * i != n) {
                d[n / i]++;
            }
        }
    }

    for(int nei : adj[curr]) {
        if(nei != from) {
            traverse(nei, curr, adj);
        }
    }
}

bool isOk(int n, int grp) {
    if(n / grp == d[grp]) {
        return true;
    }

    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    int u, v;
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    s = vector<int>(n + 1, -1);
    d = vector<int>(n + 1, 0);

    dfs(1, -1, adj);

    traverse(1, -1, adj);
    // for(int i = 1; i <= n; ++i) {
    //     cout << d[i] << " ";
    // }
    // cout << "\n";

    for(int i = n - 1; i >= 1; --i) {
        if(n % i == 0 && isOk(n, i)) {
            cout << n / i - 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}
