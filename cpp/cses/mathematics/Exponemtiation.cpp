#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD (int) (1e9 + 7)

ll qpow(ll a, ll b) {
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

int main() { _
    int n;
    cin >> n;
    while(n--) {
        ll a, b;
        cin >> a >> b;
        cout << qpow(a, b) << "\n";
    }
    return 0;
}