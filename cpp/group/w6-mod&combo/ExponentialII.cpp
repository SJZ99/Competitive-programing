#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

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

const ll mod = 1000000007;

int main(void) {

    int n;
    cin >> n;

    while(n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        cout << qpow(a, qpow(b, c, mod - 1l), mod) << "\n";
    }
    
    return 0;
}
