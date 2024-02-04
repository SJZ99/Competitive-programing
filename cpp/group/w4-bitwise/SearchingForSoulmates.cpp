#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

ll toMid(ll a, ll b) {
    if(a > b) {
        return 1e16;
    } else if(a * 2 > b) {
        return b - a;
    } else if(b & 1) {
        return toMid(a, b - 1) + 1;
    } else return toMid(a, (b >> 1)) + 1;
}

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll a, b;
        cin >> a >> b;

        if(a == b) {
            cout << "0\n";
            continue;
        }

        ll res = toMid(a, b);

        // find mid
        ll cnt = 0;
        while(a > 1) {
            ll tmp = toMid(a, b);
            res = min(res, cnt + tmp);

            if(a & 1) a++;
            else a >>= 1;

            cnt++;
        }

        cout << res << "\n";

    }

    return 0;
}