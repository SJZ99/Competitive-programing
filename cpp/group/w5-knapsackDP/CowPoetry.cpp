#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

const ll mod = 1000000007;

int syllables[5001];
int rhyme[5001];

ll dp[5001];
int r[5002];

inline ll qpow(ll x, ll y, ll n) {
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

int main(void) {

    ifstream in;
    in.open("poetry.in");

    ofstream out;
    out.open("poetry.out");

    int n, m, k;
    in >> n >> m >> k;

    for(int i = 0; i < n; ++i) {
        in >> syllables[i] >> rhyme[i];
    }

    dp[0] = 1;

    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= syllables[j]) {
                dp[i] += dp[i - syllables[j]];
                dp[i] %= mod;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        r[rhyme[i]] += dp[k - syllables[i]];
        r[rhyme[i]] %= mod;
    }

    map<int, int> cnt;
    string s;
    for(int i = 0; i < m; ++i) {
        in >> s;
        cnt[s[0] - 'A']++;
    }

    ll ans = 1;
    for(auto p : cnt) {
        int times = p.second;
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            // cout << i << " " << r[i] << endl;
            if(r[i] > 0) {
                sum += qpow(r[i], times, mod);
                sum %= mod;
            }
        }

        ans *= sum;
        ans %= mod;
    }

    out << ans << "\n";

    return 0;
}
