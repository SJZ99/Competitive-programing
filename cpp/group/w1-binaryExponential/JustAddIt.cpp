#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MOD 10000007
using namespace std;
using ll = long long int;

inline ll qpow(ll x, ll y, ll n) {
    if(x == 0) {
        return 0;
    }
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
    int n, k;
    cin >> n >> k;

    while(n != 0 && k != 0) {
        ll res = (2 * qpow(n - 1, k, MOD)) % MOD;
        res %= MOD;
        
        res += qpow(n, k, MOD);
        res %= MOD;
        
        res += (2 * qpow(n - 1, n - 1, MOD)) % MOD;
        res %= MOD;


        res += qpow(n, n, MOD);
        res %= MOD;
        cout << res << "\n";
        
        cin >> n >> k;
    }

    return 0;
}