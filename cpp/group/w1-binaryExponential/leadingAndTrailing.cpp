#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll x, y, rx, ry;
        cin >> x >> y;
        
        rx = x;
        ry = y;

        ll res = 1;
        while(y != 0) {
            if(y & 1) {
                res *= x;
                res %= 1000;
            }
            x *= x;
            x %= 1000;
            y = (y >> 1);
        }

        x = rx;
        y = ry;
        ll lead = pow(10, (y * log10(x) - floor(y * log10(x)))) * 100;
        cout << lead << "...";

        vector<int> trail;
        for(int i = 0; i < 3; ++i) {
            trail.push_back(res % 10);
            res /= 10;
        }

        cout << trail[2] << trail[1] << trail[0] << "\n";
    }

    return 0;
}