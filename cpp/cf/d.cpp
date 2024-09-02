#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
// const long double eps = 1e-16;
const long double eps = numeric_limits<long double>().epsilon();
 
bool equal(ll x, long double tar) {
    long double res = (x / log(x) );
    return abs(res - tar) < eps;
}
 
bool equalGreater(ll x, long double tar) {
    long double res = ( x / log(x) );
    cout << (x / log(x)) << " " << tar << "\n";
    return (res - tar) >= -eps;
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll a, b;
    cin >> a >> b;
 
    long double tar = (b / (log(a)) );
 
    if(a == b && a == 1) {
        cout << "1\n";
        return 0;
    }
 
    if(equal(2, tar)) {
        cout << 2 << "\n";
        return 0;
    }
 
    ll l = 3, r = (ll) 1e18 + 1, m;
 
    while(r - l > 1ll) {
        m = l + (r - l) / 2;
 
        if(equalGreater(m, tar)) {
            r = m;
        } else {
            l = m;
        }

        cout << l << " " << (m / log(m)) << " " << tar << " " << r << "\n";
    }
 
    if(equal(r, tar)) {
        cout << r << "\n";
    } else {
        cout << "0\n";
    }
 
    return 0;
}