#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;
const ll mod = (ll) 1e9 + 7ll;

int main(void) {

    ll n;
    cin >> n;
    ll rt = sqrt(n);
    ll res = 0;

    for(int i = 1; i <= rt; ++i) {

        // for(int j = i * i; j <= n; j += i) {
        //     if(j != i * i) {
        //         res += i;
        //         res += j / i;
        //     } else {
        //         res += i;
        //     }
        // }

        ll to = n / i;
        ll tmp = (((i + to) % mod) * ((to - i + 1) % mod)) % mod;
        tmp *= 500000004ll;
        tmp %= mod;

        res += tmp;
        res %= mod;

        res += ((to - i + 1) * i) % mod;
        res %= mod;

        if(i * i <= n) res -= i;
    }

    cout << res << "\n";
    
    return 0;
}
