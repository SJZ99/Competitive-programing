#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    long double r1,r2,s1,s2;
    cin >> r1 >> r2 >> s1 >> s2;

    ll a = (ll) round(r1);
    ll b = (ll) round(r2);

    long double a1 = (r1 - 1.0) / s1 * 1000000, a2 = (r2 - 1.0) / s2 * 1000000;


    if(a == 1 && b == 1) {
        cout << "SAME\n";
    } else if(a == 1) {
        cout << "TAOYUAN\n";
    } else if(b == 1) {
        cout << "JAKARTA\n";
    } else if(a1 < a2) {
        cout << "TAOYUAN\n";
    } else if(a1 > a2) {
        cout << "JAKARTA\n";
    } else {
        cout << "SAME\n";
    }

    return 0;
}