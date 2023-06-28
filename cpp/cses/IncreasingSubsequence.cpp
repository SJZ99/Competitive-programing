#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;


int optimizedLIS(vector<int>& arr) {
    vector<int> mono;
    mono.push_back(arr[0]);

    for(int i = 1; i < arr.size(); ++i) {
        if(arr[i] > mono.back()) {
            mono.push_back(arr[i]);
        } else {
            *lower_bound(mono.begin(), mono.end(), arr[i]) = arr[i];
        }
    }
    return mono.size();
}

int main() { _
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    cout << optimizedLIS(arr) << "\n";

    return 0;
}