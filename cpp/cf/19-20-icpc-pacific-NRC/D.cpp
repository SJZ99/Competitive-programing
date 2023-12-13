#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    ll a, b;
    cin >> a >> b;
    if(a <= b) {
        cout << b - a << "\n";
    } else {
        int t = 0;
        while(a != b) {
            if(a % 2 != 0) {
                a++;
            } else {
                if(a > b) {
                    a /= 2;
                } else {
                    a++;
                }
            }
            t++;
        }
        cout << t << "\n";
    }
    return 0;
}