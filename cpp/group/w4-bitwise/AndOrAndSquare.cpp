#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int arr[200000];
int cnt[20];
int main() { _
    int n;
    cin >> n;

    ll res = 0;
    ll tmp;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];

        tmp = arr[i];
        for(int j = 0; j < 20; ++j) {
            if(tmp & 1) {
                cnt[j]++;
            }
            tmp >>= 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        tmp = 0;
        int add = 1;
        for(int j = 0; j < 20; ++j) {
            if(cnt[j]) {
                cnt[j]--;
                tmp += add;
            }
            add <<= 1;
        }

        res += tmp * tmp;
    }

    cout << res << "\n";

    return 0;
}