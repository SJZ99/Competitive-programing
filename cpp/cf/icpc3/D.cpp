#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;

    vector<double> in(n);
    for(int i = 0; i < n; ++i) {
        cin >> in[i];
    }

    sort(in.begin(), in.end());

    double halfSum = in[0]  + in[in.size() - 1];
    halfSum /= 2;

    double small = *upper_bound(in.rbegin(), in.rend(), (halfSum), greater<double>());
    double big = *lower_bound(in.begin(), in.end(), (halfSum));

    // cout << halfSum << "\n";
    // cout << big << " " << small << "\n";
    // cout << abs(big - halfSum) << " " << abs(halfSum - small) << "\n";
    
    if(abs(big - halfSum) < abs(halfSum - small)) {
        cout << (ll) round(big) << "\n";
    } else {
        cout << (ll) round(small) << "\n";
    }

    return 0;
}