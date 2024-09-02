#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

const ll mod = 1000000007;

const ll N = 100001;

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
    int n;
    cin >> n;

    ll p[N] = {0};
    ll t[N] = {0};

    ll num = 1, sum = 1, prod = 1;
    ll num2 = 1;
    for(int i = 0; i < n; ++i) {
        cin >> p[i] >> t[i];

        num *= (t[i] + 1);
        num %= mod;

        sum *= ((qpow(p[i], t[i] + 1, mod) - 1) * qpow(p[i] - 1, mod - 2, mod)) % mod;
        sum %= mod;

        prod = qpow(prod, t[i] + 1, mod) * qpow(qpow(p[i], t[i] * (t[i] + 1) / 2, mod), num2, mod);
        prod %= mod;

        num2 *= (t[i] + 1);
        num2 %= (mod - 1);
    }

    cout << num << " " << sum << " " << prod << "\n";
    return 0;
}