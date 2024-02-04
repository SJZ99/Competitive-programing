#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<long long int> val(10002, 0);
vector<int> p(10002, 0);
vector<int> c[10002];

void dfs(int from, int parent) {
    if(parent != 0) {
        val[from] += val[parent];
    }

    if(c[from].size() == 0) {
        return;
    }

    for(int child : c[from]) {
        dfs(child, from);
    }
}

int main() { _
    int a, b;
    cin >> a >> b;

    for(int i = 1; i <= a; ++i) {
        cin >> val[i];
    }

    for(int i = 0; i < a - 1; ++i) {
        int u, v;
        cin >> u >> v;
        p[v] = u;
        c[u].push_back(v);
    }

    int root = 0;
    for(int i = 1; i <= a; ++i) {
        if(p[i] == 0) root = i;
    }

    dfs(root, 0);
    
    bool isFind = false;
    for(int i = 1; i <= a; ++i) {
        if(val[i] >= b) {
            isFind = true;
            cout << i << " ";
        }
    }
    if(!isFind) {
        cout << "-1";
    }
    cout << "\n";

    return 0;
}