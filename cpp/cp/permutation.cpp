#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<int> res;
bool isVisited[11];
int n, k;

void printRes() {
    for(int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << "\n";
}

void dfs(int beAdded) {
    res.push_back(beAdded);
    isVisited[beAdded] = true;
    if(res.size() == n) {
        printRes();
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!isVisited[i] && abs(i - res.back()) <= k) {
            dfs(i);
            isVisited[i] = false;
            res.pop_back();
        }
    }    
}

int main() { _
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        dfs(i);
        isVisited[i] = false;
        res.pop_back();
    }
    return 0;
}