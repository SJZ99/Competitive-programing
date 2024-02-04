#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;


unsigned long long int f(long long int from, long long int to, vector<long long int>& arr) {
    if(from > to) return 0;
    unsigned long long int res = 0;
    for(long long int i = 0; i <= (to - from); ++i) {
        res += (to - i) * (arr[arr.size() - 1 - i] - arr[0 + i]);
    }
    return res;
}

int main() { _
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<long long int> arr[m];
        for(int i = 0; i < m; ++i) {
            arr[i] = vector<long long int>(n, 0);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> arr[j][i];
            }
        }

        for(int i = 0; i < m; ++i) sort(arr[i].begin(), arr[i].end());

        unsigned long long int res = 0;
        if((n - 1) % 2 != 0) {
            for(int i = 0; i < m; ++i) {
                // cout << f(1, n / 2, arr[i]) << "dd\n";

                res += 2 * f(1, (n - 2) / 2, arr[i]);
                for(int j = 0; j < (n - 2) / 2 + 1; ++j) {
                    res += (arr[i][n - 1 - j] - arr[i][0 + j]);
                }
            }
        } else {
            for(int i = 0; i < m; ++i) {
                res += 2 * f(1, (n - 1) / 2, arr[i]);
            }
        }
        cout << res << "\n";
    }

    return 0;
}