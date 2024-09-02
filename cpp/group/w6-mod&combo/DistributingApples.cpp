#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

const ll mod = 1000000007;

inline ll qpow(ll x, ll y, ll n) {
    if(x == 0 && y == 0) return 1;
    else if(x == 0) return 0;
    
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res *= x;
            res %= n;
        }
        x *= x;
        x %= n;

        y = (y >> 1);
    }
    return res;
}

int main() { _
    ll n, m;
    cin >> n >> m;

    ll res = 1;
    for(int i = m + 1; i <= n + m - 1; ++i) {
        res *= i;
        res %= mod;
    }

    for(int i = 1; i <= n - 1; ++i) {
        res *= qpow(i, mod - 2, mod);
        res %= mod;
    }

    cout << res << "\n";
    return 0;
}