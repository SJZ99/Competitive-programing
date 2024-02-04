#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int pri[(int)1003];
int page[(int)1003];
int dp[(int)1e8 + 3];

int main() { _
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; ++i) {
        cin >> pri[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> page[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = x; j >= 0; --j) {
            if(j >= pri[i]) {
                dp[j] = max(dp[j], dp[j - pri[i]] + page[i]);
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}