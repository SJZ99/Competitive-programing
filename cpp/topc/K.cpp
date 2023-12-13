#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    string s;
    cin >> s;
    
    string ki = "kick";
    ll res = 0;
    for(int i = 0; i < s.size(); ++i) {
        for(int j = 0; j < 4; ++j) {
            if(s[i + j] != ki[j]) {
                break;
            }

            if(j == 3) {
                res++;
            }
        }
    }

    cout << res << "\n";
}