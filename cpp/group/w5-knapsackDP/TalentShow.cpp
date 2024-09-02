#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

#define INF ll(1e18)

using namespace std;
using ll = long long int;

int tal[251];
int w[251];

int n, W;

// check if target ratio can be achieved
bool f(ll tar) {
    ll dp[1001] = {0};
    for(int i = 0; i < 1001; ++i) {
        dp[i] = -INF;
    }

    dp[0] = 0;

    for(int i = 0; i < n; ++i) {
        ll val = 1000ll * tal[i] - w[i] * tar;
        
        for(int j = W; j >= 0; --j) {
            int nxt = min(W, j + w[i]);
            if(dp[j] > -INF) {
                dp[nxt] = max(dp[nxt], dp[j] + val);
            }
        }
    }
    return dp[W] >= 0;
}

int main(void) {
    ifstream in;
    in.open("talent.in");

    ofstream out;
    out.open("talent.out");

    in >> n >> W;

    for(int i = 0; i < n; ++i) {
        in >> w[i] >> tal[i];
    }

    ll l = 0, r = 25 * 1e7 + 1;
    ll m;

    while(r - l > 1) {
        m = l + (r - l) / 2;
        if(f(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    out << l << "\n";
    return 0;
}
