#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t, q;
    cin >> t >> q;

    vector<long long int> arr(t, 0);
    vector<long long int> prefix(t, 0);

    for(int i = 0; i < t; ++i) {
        cin >> arr[i];
        if(i > 0) {
            prefix[i] = prefix[i - 1] + arr[i];
        } else prefix[0] = arr[0];
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b - 1] - prefix[a - 1] + arr[a - 1] << "\n";
    }

    return 0;
}