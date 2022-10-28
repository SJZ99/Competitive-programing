#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> sta;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'Q') {
                sta.push('Q');

            } else if(s[i] == 'A') {
                if(!sta.empty()) {
                    sta.pop();
                }
            }
        }

        if(sta.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}