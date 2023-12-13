#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MX = 1e9+1, MN = -1e9-1;
int n, l = MX, r = MN, u = MN, d = MX;
signed main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z; // z = radius
        l = min(l, x-z);
        r = max(r, x+z);
        d = min(d, y-z);
        u = max(u, y+z);
    }
    cout << u-d << ' ' << r-l << '\n';
}