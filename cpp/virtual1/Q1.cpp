#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << "1 ";
        for(int i = 3; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "2\n";
    }
    return 0;
}