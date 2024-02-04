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
        int half = n / 2 + (n % 2 != 0 ? 1 : 0);
        int small = n / 2 + (n % 2 != 0 ? 1 : 0);
        while(n != half) {
            cout << small-- << " " << n-- << " ";
        }
        if(small > 0) {
            cout << small;
        }
        cout << "\n";
    }
    return 0;
}