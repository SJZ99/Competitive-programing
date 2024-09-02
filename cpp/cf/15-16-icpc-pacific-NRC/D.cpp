#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) { _
    int a[3], b[3];
    for(int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < 3; ++i) {
        cin >> b[i];
    }

    sort(a, a + 3);
    sort(b, b + 3);

    if(a[0] * a[0] + a[1] * a[1] != a[2] * a[2]) {
        cout << "NO\n";
        return 0; 
    }

    if(b[0] * b[0] + b[1] * b[1] != b[2] * b[2]) {
        cout << "NO\n";
        return 0;
    }

    if(a[0] != b[0] || a[1] != b[1] || a[2] != b[2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
