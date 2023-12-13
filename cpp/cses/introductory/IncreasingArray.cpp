#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    int arr[(int) 2e5 + 1] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll res = 0;
    for(int i = 1; i < n; ++i) {
        if(arr[i] >= arr[i - 1]) {
            continue;
        } else {
            res += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << res << "\n";
    return 0;
}