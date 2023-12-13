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

int main() { _
    ll n, m;
    cin >> n >> m;
    
    matrix stat(m + 1, vec(1, 0));
    stat[m][0] = 1;

    matrix trans(m + 1, vec(m + 1, 0));
    for(int i = 0; i < m; ++i) {
        trans[i][i + 1] = 1;
    }
    trans[m][m] = 1;
    trans[m][1] = 1;

    qpow(trans, stat, n);

    cout << stat[m][0] << "\n";
    return 0;
}