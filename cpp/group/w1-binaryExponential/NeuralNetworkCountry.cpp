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
    // # of node in a layer, # of layer, divided by m
    int n, l, m;
    cin >> n >> l >> m;

    matrix trans(m, vec(m, 0));
    matrix finalTrans(m, vec(m, 0));
    matrix stat(m, vec(1, 0));

    // read stat
    int temp;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        stat[temp][0] += 1;
    }

    vec v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        v[i] = temp;
    }

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        for(int j = 0; j < m; ++j) {
            int pos = (j - v[i] + m) % m;
            trans[j][pos] += 1;
            finalTrans[j][(pos - temp + m) % m] += 1;
        }
    }

    // for(int i = 0; i < m; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << finalTrans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    qpow(trans, stat, l - 2);
    qpow(finalTrans, stat, 1);
    cout << stat[0][0] << "\n";

    return 0;
}