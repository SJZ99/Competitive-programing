#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) {
    int tc;
    cin >> tc;

    while(tc--) {
        ll n, k;
        cin >> n >> k;

        ll maxx = 4 * n - 2;

        if(k <= maxx - 2) {
            if(k & 1) {
                cout << (k + 1) / 2 << "\n";
            } else cout << k / 2 << "\n";

        } else {
            int plus = k - maxx + 2;
            cout << (maxx - 2) / 2 + plus << "\n";
        }

    }    
    return 0;
}
