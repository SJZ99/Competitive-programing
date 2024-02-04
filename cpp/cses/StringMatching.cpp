#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

using ll = long long int;

ll Hash(string s, ll x, ll p) {

    ll res = 0;
    for(int i = 0; i < s.size(); ++i) {
        res *= x;
        res %= p;
        res += (s[i] - 'a' + 1) % p;
        res %= p;
    }
    return res;
}

ll Pow(ll x, ll p, ll mod) {
    ll res = 1;
    while(p > 0) {
        if(p & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return res;
}

int main() { _
    string a, b;
    cin >> a >> b;

    if(b.size() > a.size()) {
        cout << "0\n";
        return 0;
    }

    ll mod = 910474241;
    ll tar = Hash(b, 70, mod);
    
    vector<ll> prefix(a.size() + 1, 0);
    for(int i = 0; i < a.size(); ++i) {
        prefix[i + 1] = prefix[i] * 70;
        prefix[i + 1] %= mod;
        prefix[i + 1] += a[i] - 'a' + 1;
        prefix[i + 1] %= mod;
    }


    int res = 0;
    for(int i = 0; i <= a.size() - b.size(); ++i) {
        int r = i + b.size() - 1;
        int l = i;


        ll d = (prefix[r + 1] - prefix[l] * Pow(70, b.size(), mod) % mod + mod) % mod;

        if(d == tar) {
            res++;
        }
    }
    cout << res << "\n";
    
    return 0;
}