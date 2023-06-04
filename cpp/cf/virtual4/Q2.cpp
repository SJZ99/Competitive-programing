#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<vector<int>> m(1000, vector<int>(1000, 0));
int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n, k;
        cin >> n >> k;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> m[i][j];
            }
        }

        if(n == 1) {
            cout << "YES\n";
            continue;
        }

        int maxI;
        if(n % 2 == 0) maxI = n / 2;
        else maxI = (n + 1) / 2;

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(m[i][j] != m[n - 1 - i][n - 1 - j]) {
                    cnt++;
                }
            }
        }

        cnt /= 2;

        // cout << cnt << "\n";
        if(k >= cnt && (((k - cnt) % 2) == 0 || n % 2 != 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    

    return 0;
}