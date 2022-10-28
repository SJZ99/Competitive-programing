#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int n, k;
    cin >> n >> k;
    int arr[n];
    // number, times
    unordered_map<int, int> map;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    for(int i = 1; i < k; ++i) {
        if((map[i] % (i + 1)) == 0) {
            map[i + 1] += (map[i] / (i + 1));
        } else {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}