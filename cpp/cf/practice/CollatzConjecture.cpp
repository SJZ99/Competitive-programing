#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) { _
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    set<ll> gcds1;
    set<ll> gcds2;
    set<ll> total;

    gcds1.insert(arr[0]);
    for(int i = 1; i < n; ++i) {
        for(ll tmp : gcds1) {
            gcds2.insert(__gcd(tmp, arr[i]));
            total.insert(tmp);
        }
        gcds2.insert(arr[i]);

        gcds1 = gcds2;
        gcds2.clear();
    }

    for(ll gcd : gcds1) {
        total.insert(gcd);
    }

    cout << total.size() << "\n";

    // for(ll gcd : total) {
    //     cout << gcd << " ";
    // }
    
    return 0;
}
