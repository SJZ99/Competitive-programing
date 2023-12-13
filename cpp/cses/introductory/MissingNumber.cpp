#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;

    vector<bool> has(n + 1);

    int temp;
    for(int i = 0; i < n - 1; ++i) {
        cin >> temp;
        has[temp] = true;
    }

    for(int i = 1; i <= n; ++i) {
        if(!has[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}