#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define  N 1073676287
using namespace std;
using ll = unsigned long long int;

typedef vector<vector<ll>> Matrix;

Matrix matrixMultiply(Matrix& a, Matrix& b) {
    int m = a.size(), n = b[0].size();
    Matrix res = vector<vector<ll>>(m, vector<ll>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < b.size(); ++k) {
                res[i][j] = (res[i][j] + (a[i][k] % N) * (b[k][j] % N)) % N;
            }
        }
    }
    return res;
}

Matrix matrixPower(Matrix m, ll pow) {
    Matrix res = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    for(; pow; pow >>= 1, m = matrixMultiply(m, m))
        if(pow & 1)
            res = matrixMultiply(res, m);
    return res;
}

int main() { _

    Matrix transformation = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };


    Matrix f1 = {
        {1},
        {2},
        {4},
        {8},
        {16},
        {32},
    };

    ll n;
    cin >> n;
    if(n <= 6) {
        cout << f1[n - 1][0] << "\n";
        return 0;
    }

    Matrix finalTrans = matrixPower(transformation, (n - 6));


    cout << matrixMultiply(finalTrans, f1)[5][0] % N << "\n";


    return 0;
}