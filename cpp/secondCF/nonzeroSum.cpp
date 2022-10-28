#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

vector<pair<int, int>> makeNonzero(int arr[], int n) {
    vector<pair<int, int>> res;
    int nonzero = -1;
    for(int i = 0; i < n; ++i) {
        // find two nonzero element
        if(nonzero == -1 && arr[i] != 0 && arr[i + 1] != 0) {
            if(arr[i] == arr[i + 1]) {
                res.push_back({i + 1, i + 2});
            } else {
                res.push_back({i + 1, i + 1});
                res.push_back({i + 2, i + 2});
            }
            ++i;
        
        // find first nonzero element
        } else if(arr[i] != 0 && nonzero == -1) {
            nonzero = i;
        } else if(arr[i] == 0 && nonzero == -1) {
            res.push_back({i + 1, i + 1});

        // find second nonzero element
        } else if(arr[i] != 0) {
            if(arr[nonzero] == arr[i]) {
                res.push_back({nonzero + 1, i - 1});
                res.push_back({i, i + 1});
            } else {
                res.push_back({nonzero + 1, i});
                res.push_back({i + 1, i + 1});
            }
            nonzero = -1;
        }
    }
    return res;
}

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum % 2 != 0) {
            cout << "-1\n";
            continue;
        }

        auto res = makeNonzero(arr, n);

        cout << res.size() << "\n";
        for(int i = 0; i < res.size(); ++i) {
            cout << res[i].first << " " << res[i].second << "\n";
        }
    }
    return 0;
}