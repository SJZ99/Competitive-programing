#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

vector<ll> dp((int) 1e6 + 10, -1);
ll solve(int x) {
    if(x < 10) {
        return 1;
    }
    if(dp[x] != -1) {
        return dp[x];
    }

    int xp = x;
    ll res = INT_MAX;
    while(xp > 0) {
        int subtract = xp % 10;
        xp /= 10;
        if(subtract == 0) continue;
        res = min(res, solve(x - subtract));
    }
    res++;
    dp[x] = res;
    return res;
}

int main() { _
    int n;
    cin >> n;

    cout << solve(n) << "\n";

    return 0;
}