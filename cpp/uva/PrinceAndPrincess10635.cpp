#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> Point;

int ps[62502], qs[62502];
unordered_map<int, int> at;
vector<int> arr;

int binarySearch(vector<int>& mono, vector<int>& arr, int tar, int len) {
    int l = 0, r = len, m;
    while(r - l > 1) {
        m = (l + r) / 2;
        if(arr[tar] > arr[mono[m]]) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int main() { _
    int tc;
    cin >> tc;
    arr.reserve(60000);

    for(int i = 1; i <= tc; ++i) {
        arr.clear();
        at.clear();

        int n, p, q;
        cin >> n >> p >> q;

        for(int j = 0; j <= p; ++j) {
            cin >> ps[j];
            at.insert({ps[j], j});
        }

        for(int j = 0; j <= q; ++j) {
            cin >> qs[j];
            if(at.find(qs[j]) != at.end()) {
                arr.push_back(at[qs[j]]);
            }
        }

        vector<int> mono(arr.size(), -1);
        mono.clear();
        int len = 0;
        mono[0] = arr[0];

        for(int j = 1; j < arr.size(); ++j) {
            if(arr[j] > arr[mono[len]]) {
                mono[len + 1] = j;
                len++;
            } else if(arr[j] < arr[mono[0]]) {
                mono[0] = j;
            } else if(arr[j] < arr[mono[len]]) {
                int index = binarySearch(mono, arr, j, len);
                mono[index] = j;
            }
        }

        // for(int j = 0; j < arr.size(); ++j) {
        //     cout << arr[j] << " ";
        // }
        // cout << "\n";

        // for(int j = 0; j <= len; ++j) {
        //     cout << arr[mono[j]] << " ";
        // }
        // cout << "\n";

        cout << "Case " << i << ": " << len + 1 << "\n";

    }



    return 0;
}