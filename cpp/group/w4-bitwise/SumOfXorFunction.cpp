#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

const ll mod = 998244353;

int a[300001];

int main() { _

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = 0;
    for(int i = 0; i < 31; ++i) {

        ll eCnt = 1, eSum = 0, oCnt = 0, oSum = 0;
        ll res = 0;
        ll x = 0;
        for(int j = 0; j < n; ++j) {
            x ^= ((a[j] >> i) & 1);
            if(x) {
                res += eCnt * (j + 1) - eSum;
                res %= mod;

                oCnt++;
                oSum += (j + 1);
                oSum %= mod;
            } else {
                res += oCnt * (j + 1) - oSum;
                res %= mod;

                eCnt++;
                eSum += (j + 1);
                eSum %= mod;
            }
        }


        sum += (res * ((1ll << i) % mod)) % mod;
        sum %= mod;
    }

    cout << sum << "\n";

    return 0;
}