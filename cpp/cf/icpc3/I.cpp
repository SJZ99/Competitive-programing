#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    ll n;
    cin >> n;
    
    ll sq = sqrt(n);
    ll p = LLONG_MAX;
    for(ll i = 1; i <= n; ++i) {
        if(i * i / n - n > 0) {
            p = min(p, i * i / n - n);
        }
    }

    cout << p << "\n";
    return 0;
}