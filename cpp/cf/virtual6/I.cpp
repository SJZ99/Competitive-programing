#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int a, b;
    cin >> a >> b;

    ll res = 0;
    int len = a - b;
    res += len * 3;
    len -= b;

    while(len > 0) {
        res += len * 2;
        len -= b;
    }

    cout << res << "\n";
    return 0;
}