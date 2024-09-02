#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll qpow(ll base,ll deg, ll mod){
    ll sum = 1;
    while(deg > 0){
        if(deg & 1){
            sum = sum*base%mod;
        }
        deg >>= 1;
        base = base*base%mod;
    }
    return sum;
}

ll rev(ll num, ll p) {
    return qpow(num, p - 2, p);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, p, r;
    cin >> n >> p >> r;

    if(n >= 2 * p && r != 0) {
        cout << "-1 -1\n";
        return 0;
    } 
    else if (n >= 2 * p) {
        for(int i = 2; i <= n; ++i) {
            if(i != p) {
                cout << i << " 1\n";
                return 0;
            }
        }
    } else if(n < p && r == 0) {
        cout << "-1 -1\n";
        return 0;
    }

    ll res = 1;
    for(ll i = 2; i <= n; ++i) {
        if(i % p == 0) continue;
        res *= i;
        res %= p;
    }

    ll revfac = rev(res, p);

    ll a = 0;

    if(n >= p) {
        if(r == 0) {
            for(int i = 2; i <= n; ++i) {
                if(i != p) {
                    cout << i << " 1\n";
                    return 0;
                }
            }
        }

        ll tmp;
        for(ll a = 1; a < p; ++a) {
            tmp = res * a % p;
            if(tmp == r) {
                cout << p << " " << a << "\n";
                return 0;
            }
        }
        cout << "-1 -1\n";
        return 0;
    }

    for(ll b = 2; b <= n; ++b) {
        a = (b * revfac) % p;
        a *= r;
        a %= p;

        if(b > a) {
            cout << b << " " << a << "\n";
            return 0;
        }
    }

    cout << "-1 -1\n";
    return 0;
}