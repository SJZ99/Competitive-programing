#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define N (int)1e5
using namespace std;

vector<vector<int>> child;

int diameter = 0;
int dfs(int me) {

    int m1 = 0, m2 = 0;
    for(int node : child[me]) {
        int temp = dfs(node) + 1;
        if(temp > m1) m2 = m1, m1 = temp;
        else if(temp > m2) m2 = temp;
        diameter = max(diameter, m1 + m2);
    }
    return m1;
}

bool hasParent[N];
int main() { _
    int n;
    while(cin >> n) {
        child.clear();
        child = vector<vector<int>>(N, vector<int>());
        diameter = 0;
        memset(hasParent, 0, sizeof(bool) * N);

        int p, c;
        int from;
        for(int i = 0; i < n - 1; ++i) {
            cin >> p >> c;
            child[p].push_back(c);
            hasParent[c] = true;
        }

        int root;
        for(int i = 0; i < n; ++i) {
            if(!hasParent[i]) {
                root = i;
            }
        }

        dfs(root);
        cout << diameter << "\n";
        
    }
    return 0;
}