#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

ll gcd(ll a, ll b) {
    if(b > a) {
        ll temp = a;
        a = b;
        b = temp;
    }

    ll r = 0;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool is_prime(ll x) {
    if(x == 1) return false;
    if(x == 0) return false;
    ll sq = sqrt(x) + 1;
    for(ll i = 2; i < sq; ++i) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() { _

    int tc;
    cin >> tc;

    double a, b;
    while(tc--) {
        cin >> a >> b;
        a *= 1e5;
        b *= 1e5;

        ll ai = (ll) round(a);
        ll bi = (ll) round(b);

        if(ai == bi && ai != 0) {
            cout << "2 2\n";
            continue;
        } else if(ai == bi) {
            cout << "impossible\n";
            continue;
        }

        ll g = gcd(ai, bi);
        // cout << "gcd: " << g << "\n";
        ai /= g;
        bi /= g;
        // cout << ai << " " << bi << "\n";
        if(is_prime(ai) && is_prime(bi)) {
            cout << ai << " " << bi << "\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}