#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

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

int main() { _
    string s;
    cin >> s;

    int arr[26] = {0};
    for(int i = 0; i < s.size(); ++i) {
        arr[s[i] - 'a']++;
    }

    fat[0] = 1;
    for(int i = 1; i <= 1000000; ++i) {
        fat[i] = fat[i - 1] * i % mod;
    }

    ll res = fat[s.size()];
    for(int i = 0; i < 26; ++i) {
        if(arr[i] > 1) {
            res *= qpow(fat[arr[i]], mod - 2, mod);
            res %= mod;
        }
    }

    cout << res << "\n";
    return 0;
}