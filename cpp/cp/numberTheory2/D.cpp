#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

ll extendedEuclid(ll a, ll b) {
    ll rawB = b;
    bool swaped = false;
    if(b > a) {
        ll t = a;
        a = b;
        b = t;
        swaped = true;
    }
    ll temp;
    ll si[3], ti[3];
    ll qi;
    si[0] = 1, si[1] = 0;
    ti[0] = 0, ti[1] = 1;

    while(b) {
        temp = a % b;
        qi = a / b;
        si[2] = si[0] - qi * si[1];
        ti[2] = ti[0] - qi * ti[1];

        // cout << si[2] << " " << ti[2] << "\n";

        if(temp == 0) {
            break;
        }

        for(int i = 0; i < 2; ++i) {
            si[i] = si[i + 1];
            ti[i] = ti[i + 1];  
        }
        a = b, b = temp;
    }

    if(b == 1) {
        if(swaped) {
            return (ti[1] + rawB) % rawB;
        } else {
            return (si[1] + rawB) % rawB;
        }
    } else {
        return -1;
    }
    
}

int main() { _
    
    ll p, q;
    cin >> p >> q;
    cout << extendedEuclid(p, q) << "\n";
    return 0;
}