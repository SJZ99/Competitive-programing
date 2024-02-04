#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    double k1, k2;
    cin >> k1 >> k2;

    ll upper = floor(min(3 * (k1 + 0.4), 2 * (k2 + 0.4)));
    ll lower = ceil(max(3 * (k1 - 0.5), 2 * (k2 - 0.5)));

    // cout << 3 * (k1 + 0.4) << " " << 2 * (k2 + 0.4) << "\n";
    // cout << 3 * (k1 - 0.5) << ' ' << 2 * (k2 - 0.5) << "\n";

    // cout << upper << " " << lower << "\n";
    if(upper - lower >= 0) {
        for(int i = lower; i <= upper; ++i) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "0\n";
    }
    return 0;
}