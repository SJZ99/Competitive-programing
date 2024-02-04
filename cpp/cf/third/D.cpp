#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;
        cin >> n >> m;

        int a[200001] = {0};
        int c[200001] = {0};

        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for(int i = 0; i < m; ++i) {
            cin >> c[i];
        }
        sort(a, a + n);
        sort(c, c + m);

        int h1 = 0, t1 = n - 1;
        int h2 = 0, t2 = m - 1;

        ll sum = 0;
        ll tmp;
        for(int i = 0; i < n; ++i) {
            ll dif1 = abs(a[h1] - c[h2]);
            ll dif2 = abs(a[h1] - c[t2]);
            ll dif3 = abs(a[t1] - c[h2]);
            ll dif4 = abs(a[t1] - c[t2]);
            tmp = max(max(dif1, dif2), max(dif3, dif4));

            sum += tmp;
            if(tmp == dif1) {
                h1++, h2++;
            } else if(tmp == dif2) {
                h1++, t2--;
            } else if(tmp == dif3) {
                t1--, h2++;
            } else {
                t1--, t2--;
            }
            
        }
        cout << sum << "\n";
    }

    return 0;
}