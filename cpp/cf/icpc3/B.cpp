#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
int main() { _
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> prefix(n+1, 0);

    for(int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int tc;
    cin >> tc;

    while(tc--) {
        ll q;
        cin >> q;

        ll i = upper_bound(arr.begin(), arr.end(), q) - arr.begin();

        if(i < n) {
            cout << prefix[n] - prefix[i] - q * (n - i) << "\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}