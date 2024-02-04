#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define N 4098
int main() { _
    int n, m, q;
    cin >> n >> m >> q;

    cin.ignore();
    // cin.ignore();
    // cin.ignore();

    int arr[N] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        cin.ignore();
    }

    char c;
    map<int, int> ms;
    for(int i = 0; i < m; ++i) {
        int mul = (1 << (n - 1));
        int tmp = 0;
        for(int j = n - 1; j >= 0; --j) {
            cin >> c;
            tmp += mul * (c == '1');
            mul >>= 1;
        }
        ms[tmp]++;
        // cout << tmp << endl;
        cin.ignore();
    }

    int fs = (1 << n) - 1;
    int res[N][101] = {0};
    int tmp;
    for(int i = 0; i <= fs; ++i) {
        for(auto& p : ms) {
            tmp = 0;
            int str = p.first;
            for(int j = 0; j < n; ++j) {
                if((~(i ^ str)) & (1 << j)) {
                    tmp += arr[n - j - 1];
                }
                if(tmp > 100) break;
            }

            if(tmp < 101) {
                // cout << i << " " << tmp << " " << p.second << endl;
                res[i][tmp] += p.second;
            } 
        }
    }

    // cout << res[0][0] << "\n";
    for(int str = 0; str <= fs; ++str) {
        for(int i = 1; i <= 100; ++i) {
            res[str][i] = res[str][i] + res[str][i - 1];
        }
    }

    int maxx;
    for(int i = 0; i < q; ++i) {
        int mul = (1 << (n - 1));
        tmp = 0;
        for(int j = n - 1; j >= 0; --j) {
            cin >> c;
            tmp += mul * (c == '1');
            mul >>= 1;
        }
        cin.ignore();
        cin >> maxx;
        cin.ignore();

        cout << res[tmp][maxx] << "\n";
    }

    return 0;
}