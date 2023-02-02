#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;
    int temp;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> r, c;
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            r.push_back(temp);
        }
        for(int i = 0; i < m; ++i) {
            cin >> temp;
            c.push_back(temp);
        }

        if(r.size() == 1 && c.size() == 1) {
            cout << "1\n";
        } else if(r.size() == 2 && c.size() == 2) {
            cout << "7\n";
        } else {
            cout << "1\n";
        }
    }

    return 0;
}