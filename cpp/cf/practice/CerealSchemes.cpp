#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int arr[n] = {};
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = 0;
    for(int i = 30; i >= 0; --i) {
        int tar = res | (1 << i);
        int cnt = 0;
        int curr = 0;
        for(int j = 0; j < n; ++j) {
            curr |= arr[j];
            if((curr & tar) == tar) {
                cnt++;
                curr = 0;
            }
        }

        if(cnt >= k) res |= (1 << i);
    }

    cout << res << "\n";
    return 0;
}