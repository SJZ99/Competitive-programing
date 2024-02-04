#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n, q;
        cin >> n >> q;

        int arr[100001] = {0};
        ll s[100002] = {0}; // sum of [l, r] = s[r + 1] - s[l];
        ll x[100002] = {0}; // xor of [l, r] = x[r + 1] ^ x[l]

        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            s[i + 1] = s[i] + arr[i];
            x[i + 1] = x[i] ^ arr[i];
        }
        int l, r;
        cin >> l >> r;
        // l--;

        ll maxx = s[n] - x[n];

        int ml = l, mr = r;

        for(l; l <= n; ++l) {
            r = l;

            while(s[r] - s[l - 1] - (x[r] ^ x[l - 1]) != maxx && r <= n) {
                r++;
            }
            
            if(r > n) break;

            if(r - l < mr - ml) {
                ml = l, mr = r;
            }
        }

        cout << ml << " " << mr << "\n";
    }

    return 0;
}