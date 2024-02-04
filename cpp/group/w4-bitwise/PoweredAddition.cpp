#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    int tc;
    cin >> tc;

    while(tc--) {

        int n;
        cin >> n;

        ll maxx = -1e9;
        ll d = 0;
        ll tmp;
        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            maxx = max(maxx, tmp);
            d = max(d, maxx - tmp);
        }

        int cnt = 0;
        while(d > 0) {
            d >>= 1;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}