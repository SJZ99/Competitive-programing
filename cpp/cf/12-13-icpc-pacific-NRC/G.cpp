#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

ll thr[56], two[56];

ll binomial(ll n, ll r) {

    if(n - r < r) {
        r = n - r;
    }

    if(r == 0) {
        return 1;
    }

    ll res = 1;
    for(ll i = r + 1; i <= n; ++i) {
        res *= i;
    }

    for(ll i = 2; i <= r; ++i) {
        res /= i;
    }

    return res;
}

ll solve(ll n, ll r) {
    if(r == 3) {
        return thr[n];
    } else if(r == 2) {
        return two[n];
    } else if(r == 1) {
        return n;
    } else {
        return 0;
    }
}

int main(void) {
    thr[1] = thr[2] = 0, thr[3] = 1;
    two[1] = 0, two[2] = 1, two[3] = 3;

    for(int i = 4; i <= 55; ++i) {
        thr[i] = thr[i - 1];
        two[i] = two[i - 1];

        for(int j = 3; j <= i - 1; j += 3) {
            thr[i] += binomial(i - 1, j);
            two[i] += binomial(i - 1, j - 2);
        }
        cout << thr[i] << " ";
    }

    ll n;
    while(cin >> n) {
        int bits = 0;
        ll res = 0;
        for(int i = 54; i >= 0 && bits < 4; --i) {
            if(n & (1ll << i)) {
                res += solve(i, (3 - (bits % 3)));
                bits++;
            }
        }

        if(bits >= 3) res++;
        cout << res << "\n";
    }
    return 0;
}
