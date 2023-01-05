#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define int unsigned int
using namespace std;

bool isSpanSuccess(int diameter, int k, int arr[], int length) {
    bool spaned[length] = {false};
    int comsumed = 0;
    for(int i = 0; i < length; ++i) {
        if(!spaned[i]) {
            comsumed++;
            int j = i + 1;
            while(j < length && (arr[i] + diameter) >= arr[j]) {
                spaned[j] = true;
                j++;
            }
        }

        if(comsumed > k) {
            return false;
        }
    }
    return true;
}

signed main() { _
    int n, k, maxDiameter;
    cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    maxDiameter = (arr[n - 1] - arr[0]) / k;

    int left = 0, right = maxDiameter, mid = 0;

    while(right - left > 1) {
        mid = (right + left) / 2;
        // cout << mid << " " << isSpanSuccess(mid, k, arr, n) << "\n";
        if(isSpanSuccess(mid, k, arr, n)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << "\n";
    return 0;
}