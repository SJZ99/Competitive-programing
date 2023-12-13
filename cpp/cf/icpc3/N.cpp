#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    ll time, n;
    cin >> time >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll r1 = 0, r2 = INT_MAX;
    do {
        ll penalty = 0;
        ll t = 0;
        ll cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(t + arr[i] <= time) {
                t += arr[i];
                penalty += t;
                penalty %= 1440;
                cnt++;
            } else break;
        }

        if(cnt > r1) {
            r1 = cnt, r2 = penalty;
        } else if(cnt == r1 && penalty < r2) {
            r2 = penalty;
        }
    } while(next_permutation(arr.begin(), arr.end()));
    cout << r1 << " " << r2 << "\n";
    return 0;
}