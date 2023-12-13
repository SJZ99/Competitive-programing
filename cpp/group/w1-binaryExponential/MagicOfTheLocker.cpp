#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MOD 1000000007L

using namespace std;
using ll = long long int;

inline ll qpow(ll x, ll y, ll n) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res *= x;
            res %= n;
        }
        x *= x;
        x %= n;

        y = (y >> 1);
        // cout << y << " ";
    }
    return res;
}

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll n;
        cin >> n;
        if(n == 1ll) {
            cout << "1\n";
            continue;
        }
        
        ll remain = n % 3;
        ll res = 0;
        if(remain == 2) {
            res = qpow(3, (n - 2) / 3, MOD);
            res *= 2;
            res %= MOD;
        } else if(remain == 1) {
            res = qpow(3, (n - 4) / 3, MOD);
            res *= 4;
            res %= MOD;
        } else {
            res = qpow(3, n / 3, MOD);
        }

        cout << res << "\n";
    }

    return 0;
}