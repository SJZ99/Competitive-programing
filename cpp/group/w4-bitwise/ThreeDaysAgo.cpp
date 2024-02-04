#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    string s;
    cin >> s;
    map<ll, ll> state;
    state[0]++;

    ll curr = 0;
    for(char c : s) {
        int p = c - '0';
        curr ^= (1 << p);
        // cout << curr;
        state[curr]++;
    }

    ll res = 0;
    for(auto& p : state) {
        res += p.second * (p.second - 1) / 2;
    }

    cout << res << "\n";

    return 0;
}