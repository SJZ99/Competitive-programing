#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

bool dp[5000005];

int main(void) { _
    ifstream in;
    in.open("feast.in");

    ofstream out;
    out.open("feast.out");

    int t, a, b;
    in >> t >> a >> b;

    dp[0] = true;
    dp[a / 2] = true;
    dp[b / 2] = true;

    if(a + b <= t) 
        dp[(a / 2) + (b / 2)] = true;
    
    for(int i = 0; i <= t; ++i) {
        if(i - a >= 0) {
            dp[i] |= dp[i - a];
        }

        if(i - b >= 0) {
            dp[i] |= dp[i - b];
        }
    }

    for(int i = t; i >= 0; --i) {
        if(dp[i]) {
            out << i << "\n";
            break;
        }
    }

    return 0;
}
