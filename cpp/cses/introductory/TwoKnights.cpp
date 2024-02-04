#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    ll n;
    cin >> n;

    cout << "0\n";
    for(ll k = 2; k <= n; ++k) {
        cout << k * k * (k * k - 1) / 2ll - 4ll * (k - 1ll) * (k - 2ll) << "\n";
    }
    return 0;
}