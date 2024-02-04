#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll x, y, n;
        cin >> x >> y >> n;

        ll res = 1;
        while(y != 0) {
            if(y & 1) {
                res *= x;
                res %= n;
            }
            x *= x;
            x %= n;

            y = (y >> 1);
        }
        cout << res << "\n";
    }

    return 0;
}