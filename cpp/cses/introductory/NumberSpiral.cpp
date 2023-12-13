#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll x, y;
        cin >> x >> y;

        ll big = max(x, y);
        ll res = big * big;

        ll tx, ty;
        if(big % 2 == 0) {
            tx = big;
            ty = 1;
        } else {
            tx = 1;
            ty = big;
        }

        res -= abs(x - tx) + abs(y - ty);
        cout << res << "\n";
    }

    return 0;
}