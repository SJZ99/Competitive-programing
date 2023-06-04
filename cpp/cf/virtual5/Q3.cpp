#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr;
        arr.reserve(n);

        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        bool isOk = false;
        if(arr[1] < arr[0]) {
            for(int i = 2; i < n; ++i) {
                if(arr[i] > arr[0] && i % 2 == 0) isOk = true;
            }
        } else isOk = true;


        if(isOk) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}