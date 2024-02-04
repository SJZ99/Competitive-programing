#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int r = 0, g = 0, b = 0;

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else if(s[i] == 'B') b++;
    }

    if(r == 0 || g == 0 || b == 0) {
        cout << "YES\n";
    } else if(r % 2 == 0 && g % 2 == 0 && b % 2 == 0) {
        cout << "YES\n";
    }  else {
        cout << "NO\n";
    }

    return 0;
}