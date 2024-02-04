#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n, x;
    cin >> n >> x;

    int arr[n] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int to = 1 << n;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < to; ++i) {
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i) {
                sum += arr[j];
            }
        }
        if(sum == x) {
            cnt++;
        }
        sum = 0;
    }
    cout << cnt << "\n";
    return 0;
}