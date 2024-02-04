#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    string str;
    cin >> str;

    int maxx = 0;
    int curr = 0;
    char pre = '\0';

    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == pre || pre == '\0') {
            pre = str[i];
            curr++;
        } else {
            pre = str[i];
            curr = 1;
        }
        maxx = max(maxx, curr);
    }

    cout << maxx << "\n";

    return 0;
}