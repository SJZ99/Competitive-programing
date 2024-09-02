#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

const ll MOD = 1e9 + 7;

ll qpow(ll a, ll b, ll MOD) {
    ll sum = 1;
    while(b > 0) {
        if(b & 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return sum;
}

int main(void) {
    ll tc;
    cin >> tc;
    while(tc--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll p = qpow(b, c, MOD - 1);
        cout << qpow(a, p, MOD) << "\n";
    }
    return 0;
}
