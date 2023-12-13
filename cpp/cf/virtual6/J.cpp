#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n; 
    cin >> n;

    vector<ll> two(n, 0);
    vector<ll> sum(n, 0);
    vector<bool> self(n, false);

    for(int i = 0; i < n; ++i) {
        ll m1 = INT_MAX;
        ll m2 = INT_MAX;
        ll temp;
        for(int j = 0; j < 3; ++j) {
            cin >> temp;
            if(temp < m1) {
                m2 = m1;
                m1 = temp;
            } else if(temp < m2) {
                m2 = temp;
            }
            sum[i] += temp;
        }
        two[i] = m1 + m2;

        if(sum[i] - 2 >= two[i]) self[i] = true;
    }

    sort(two.begin(), two.end());

    for(int i = 0; i < n; ++i) {
        ll curr = sum[i] - 1;
        int dis = lower_bound(two.begin(), two.end(), curr) - two.begin();
        if(self[i]) {
            dis--;
        }
        cout << dis << " ";
    }

    return 0;
}