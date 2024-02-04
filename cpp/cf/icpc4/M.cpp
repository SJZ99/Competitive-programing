#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;

    while(n--) {
        int t;
        cin >> t;

        if(t == 1) {
            int temp;
            cin >> temp;
            cout << temp << "\n";
            continue;
        }

        vector<int> arr(t);

        bool neg = false, pos = false;
        int ni, mi;
        ll minn = INT_MAX, maxx = INT_MIN;
        for(int i = 0; i < t; ++i) {
            cin >> arr[i];
            if(arr[i] > 0) {
                pos = true;
            } else if(arr[i] < 0) {
                neg = true;
            }

            if(arr[i] < minn) {
                minn = arr[i];
                ni = i;
            }
            if(arr[i] > maxx) {
                maxx = arr[i];
                mi = i;
            }
        }

        if(pos && !neg) {
            ll res = abs(arr[ni] - arr[(ni + 1) % t]);
            for(int i = 0; i < t; ++i) {
                if(i != ni && i != (ni + 1) % t) {
                    res += arr[i];
                }
            }
            cout << res << "\n";
        } else if(neg && !pos) {
            ll res = abs(arr[mi] - arr[(mi + 1) % t]);
            for(int i = 0; i < t; ++i) {
                if(i != mi && i != (mi + 1) % t) {
                    res += abs(arr[i]);
                }
            }
            cout << res << "\n";
        } else {
            ll res = 0;
            for(int i = 0; i < t; ++i) {
                res += abs(arr[i]);
            }
            cout << res << "\n";
        }
    }
    return 0;
}