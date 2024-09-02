#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

#define N 500001

using namespace std;
using ll = long long int;

const ll mod = 998244353;

int l[N] = {0};
int r[N] = {0};
int val[N] = {0};

int arr[N] = {0};
int ai = 0;

void dfs(int i) {
    if(i == -1) return;

    dfs(l[i]);
    arr[ai++] = val[i];
    dfs(r[i]);
}

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

ll binormial(ll n, ll k) {
    if(n == 0 || k == 0) return 1;

    ll res = 1;
    ll inv = 1;
    for(int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res %= mod;

        inv *= i;
        inv %= mod;
    }

    res *= qpow(inv, mod - 2, mod);
    res %= mod;
    return res;
}

int main(void) { _
    
    int tc;
    cin >> tc;

    while(tc--) {
        ll n, c;
        cin >> n >> c;

        for(int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i] >> val[i];
        }

        dfs(1);
        arr[ai++] = c;

        // for(int i = 0; i < ai; ++i) {
        //     cout << arr[i] << " ";
        // }cout << "\n";
        
        ll lv = 1, rv = 0;
        int cnt = 0;

        ll res = 1;
        for(int i = 0; i < ai; ++i) {
            if(arr[i] == -1) {
                cnt++;
            } else {
                rv = arr[i];
                
                res *= binormial(rv- lv + cnt, cnt);
                res %= mod;

                lv = rv;
                cnt = 0;
            }
        }
        cout << res << "\n";

        int len = sizeof(int) * n + 5;
        memset(l, 0, len);
        memset(r, 0, len);
        memset(val, 0, len);
        memset(arr, 0, len);
        ai = 0;
    }

    return 0;
}
