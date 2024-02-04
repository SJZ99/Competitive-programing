#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n, k;
        cin >> n >> k;

        vector<pair<ll, int>> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }

        sort(arr.begin(), arr.end());

        int ai = 0, aj = 1;
        ll minn = INT_MAX;
        for(int i = 1; i < n; ++i) {
            if((arr[i].first ^ arr[i - 1].first) < minn) {
                minn = (arr[i].first ^ arr[i - 1].first);
                ai = i - 1, aj = i;
            }
        }

        ll x = 0;
        for(int i = 0; i < k; ++i) {
            if((arr[ai].first & (1 << i)) == (arr[aj].first & (1 << i)) && ((arr[ai].first & (1 << i)) == 0)) {
                x |= (1 << i);
            }
        }

        cout << min(arr[ai].second, arr[aj].second) << " " << max(arr[ai].second, arr[aj].second) << " " << x << "\n";
    }
    return 0;
}