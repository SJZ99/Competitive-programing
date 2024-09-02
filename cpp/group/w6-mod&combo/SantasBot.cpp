#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

#define N 1000001

using namespace std;
using ll = long long int;

const ll mod = 998244353ll;

ll self[N];
int p[N];

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

int main(void) {
    int n;
    cin >> n;

    ll cnt, temp;
    ll maxx = 0;
    for(int i = 0; i < n; ++i) {
        cin >> cnt;
        for(int j = 0; j < cnt; ++j) {
            cin >> temp;
            self[temp] += qpow(cnt, mod - 2, mod);
            self[temp] %= mod;
            p[temp]++;
            maxx = max(maxx, temp);
        }
    }

    ll invn = qpow(n, mod - 2, mod);

    ll res = 0;
    for(int i = 0; i <= maxx; ++i) {
        if(self[i]) {
            // cout << self[i] * qpow(n, mod - 2, mod) << "\n";
            res += (((self[i] * invn) % mod) * ((p[i] * invn) % mod)) % mod;
            res %= mod;
        }
    }
    
    cout << res << "\n";
    return 0;
}
