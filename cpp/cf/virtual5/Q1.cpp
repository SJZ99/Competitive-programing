#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;

    while(t--) {
        int x, y;
        cin >> x >> y;
        cout << "2\n";
        cout << "1 " << y - 1 << "\n";
        cout << x << " " << y << "\n";
    }

    return 0;
}