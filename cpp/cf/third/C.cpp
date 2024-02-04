#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        
        ll arr[200001] = {0};
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        for(int i = 1; i <= n; ++i) {
            sum += min((arr[i] - arr[i - 1]) * a, b);
            if(sum >= f) break;
        }

        if(sum >= f) cout << "NO\n";
        else cout << "YES\n";

    }

    return 0;
}