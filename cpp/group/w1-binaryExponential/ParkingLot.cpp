#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = unsigned long long int;

int main() { _
    ll n;
    cin >> n;
    
    ll x = 4, y = n - 2;
    ll res1 = 6;
    while(y != 0) {
        if(y & 1) {
            res1 *= x;
        }
        x *= x;
        y = (y >> 1);
    }

    ll res2 = 36 * (n - 3);
    x = 4;
    y = n - 4;
     while(y != 0) {
        if(y & 1) {
            res2 *= x;
        }
        x *= x;
        y = (y >> 1);
    }
    cout << res1 + res2 << "\n";
    return 0;
}