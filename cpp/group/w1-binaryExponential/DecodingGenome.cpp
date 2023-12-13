#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define MOD 1000000007

using namespace std;
using ll = long long int;

using vec = vector<ll>;
using matrix = vector<vec>;

void mul(matrix& a, matrix& b, matrix& c) {
    int n = a.size(), m = b[0].size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            c[i][j] = 0;
            for(int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
                c[i][j] %= MOD;
            }
        }
    }
}

void qpow(matrix& a, matrix& b, ll n) {

    matrix a2(a.size(), vec(a[0].size()));
    matrix c(b.size(), vec(b[0].size()));

    while(n != 0) {
        if(n & 1) {
            mul(a, b, c);
            b = c;
        }
        mul(a, a, a2);
        a = a2;
        n = (n >> 1);
    }
}

int toNumber(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a';
    } else {
        return c - 'A' + 26;
    }
}

int main() { _
    // power, dimension, constrian
    ll n, m, k;
    cin >> n >> m >> k;
    cin.ignore();

    matrix trans(m, vec(m, 1));
    matrix row(m, vec(1, 1));

    char a, b;
    for(int i = 0; i < k; ++i) {
        cin >> a >> b;
        cin.ignore();

        trans[toNumber(b)][toNumber(a)] = 0;
    }

    // for(int i = 0; i < m; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << trans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    qpow(trans, row, n - 1);
    ll res = 0;
    for(int i = 0; i < m; ++i) {
        res += row[i][0];
        res %= MOD;
    }
    cout << res << "\n";
    return 0;
}