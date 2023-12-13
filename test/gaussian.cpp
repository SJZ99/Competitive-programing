#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;
    vector<vector<double>> m(n, vector<double>(n + 1));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {

        for(int j = i + 1; j < n; ++j) {
            double mul = m[j][i] / m[i][i];
            for(int k = i + 1; k <= n; ++k) {
                m[j][k] -= m[i][k] * mul;
            }
        }
    }
    vector<double> res;
    res.push_back(m[n - 1][n] / m[n - 1][n - 1]);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            m[n - 1 - i][n] -= m[n - 1 - i][n - 1 - j] * res[j];
        }
        res.push_back(m[n - 1 - i][n] / m[n - 1 - i][n - 1 - i]);
    }

    for(int i = res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
    }
    return 0;
}