#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    unordered_map<int, int> need;
    vector<int> res(n + 1, 0);
    for(int i = n - 1; i >= 0; --i) {
        if(arr[i] > 0) {
            need[arr[i]] = i;
            res[i] = res[i + 1] + 1;
        } else {
            int de = -arr[i];
            if(need.find(de) != need.end()) {
                res[i] = min(need[de] - i, res[i + 1] + 1);
                need.erase(de);
            } else {
                res[i] = res[i + 1] + 1;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}