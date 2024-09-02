#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

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

ll fat[1000001];
ll inv[1000001];

void prepare() {
    fat[0] = 1;
    inv[0] = 1;

    for(int i = 1; i <= 1000000; ++i) {
        fat[i] = fat[i - 1] * i % mod;
        inv[i] = qpow(fat[i], mod - 2, mod);
    }
}

ll binomial(ll n, ll r) {
    if(r > n) return 0;
    return ((fat[n] * inv[r]) % mod) * inv[n - r] % mod;
}

int main(void) { _
    int tc;
    cin >> tc;

    prepare();

    while(tc--) {
        int n, m, k;
        cin >> n >> m >> k;

        int arr[n] = {0};
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll res = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            while(j + 1 < n && arr[j + 1] - arr[i] <= k) ++j;

            res += binomial(j - i, m - 1);
            res %= mod;
        }
        cout << res << "\n";
    }
    return 0;
}