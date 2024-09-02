#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) {
    int n;
    cin >> n;

    int  arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int minn = INT_MAX;
    for(int i = 0; i < n / 2; ++i) {
        minn = min(minn, arr[i] + arr[n - i - 1]);
    }
    cout << minn << "\n";
    return 0;
}
