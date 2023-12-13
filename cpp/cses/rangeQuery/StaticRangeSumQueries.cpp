#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    int n, m;
    cin >> n >> m;

    vector<int> vals(n + 1, 0);
    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> vals[i];
        prefix[i + 1] = prefix[i] + vals[i];
    }

    int a, b;
    while(m--) {
        cin >> a >> b;
        a--, b--;
        cout << prefix[b + 1] - prefix[a] << "\n";
    }
    return 0;
}