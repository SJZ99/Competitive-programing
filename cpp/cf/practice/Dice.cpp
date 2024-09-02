#include <bits/stdc++.h>

using namespace std;
using ll = long long int;


const ll mod = 1000000007ll;

struct Mat {
    ll d[201][201];
    int m, n;

    Mat(int m, int n) : m(m), n(n) {
        memset(d, 0, sizeof(ll) * 201 * 201);
    }

    Mat operator* (const Mat& mat) {
        Mat res(m, mat.n);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < mat.n; ++j) {
                for(int k = 0; k < n; ++k) {
                    res.d[i][j] += (d[i][k] * mat.d[k][j]) % mod;
                    res.d[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

ll qpow(ll base, ll deg, ll mod){
    ll sum = 1;
    while(deg > 0){
        if(deg & 1){
            sum = sum*base%mod;
        }
        deg >>= 1;
        base = base*base%mod;
    }
    return sum;
}

Mat qpow(Mat base, ll deg){
    // base is square matrix
    Mat sum(base.m, base.m);
    for(int i = 0; i < base.m; ++i) {
        sum.d[i][i] = 1;
    }

    while(deg > 0){
        if(deg & 1){
            sum = sum*base;
        }
        deg >>= 1;
        base = base*base;
    }
    return sum;
}

int main(void) {
    ll n, k, m;
    cin >> n >> k >> m;

    ll w[201] = {};
    for(int i = 1; i <= k; ++i) {
        if(i % m != 0) {
            w[i % m]++;
            w[i % m] %= mod;
        }
    }

    ll div = qpow(k - k/m, mod-2, mod);
    for(int i = 0; i < m; ++i) {
        w[i] *= div;
        w[i] %= mod;
    }

    Mat state(m, 1);
    state.d[0][0] = 1;
    Mat trans(m, m);

    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < m; ++i) {
            trans.d[(i+j) % m][j] = w[i];
            // cout << w[(i+j)%m] << " ";
        }
        // cout << "\n";
    }

    
    
    Mat f = qpow(trans, n);
    state = f*state;

    cout << state.d[0][0] << "\n";

    return 0;
}