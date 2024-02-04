#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define MOD 1000000007

ll fpow(ll base, ll deg){
    ll sum = 1;
    while(deg > 0){
        if(deg & 1){
            sum = sum * base % MOD;
        }
        deg >>= 1;
        base = base * base % MOD;
    }
    return sum;
}

int main() { _
    int n;
    cin >> n;

    cout << fpow(2, n);
    return 0;
}