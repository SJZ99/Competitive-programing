#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    string s;
    cin >> s;

    int n = s.size();
    bool odd = true;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            string s1 = s.substr(i, j + 1);
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            if(s1 == s2 && s1.size() % 2 == 0) {
                odd = false;
                break;
            }
        }
        if(!odd) break;
    }

    if(odd) {
        cout << "Odd.\n";
    } else {
        cout << "Or not.\n";
    }
    return 0;
}