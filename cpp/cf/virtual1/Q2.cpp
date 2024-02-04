#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;

    int arr[10] = {
        0, 0, 1, 3, 6, 10, 15, 21, 28, 36
    };

    while(t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        cout << arr[(10 - n)] * 6 << "\n";
    }
    return 0;
}