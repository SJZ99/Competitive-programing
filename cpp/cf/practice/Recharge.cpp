#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {
        ll k, x, y;
        cin >> k >> x >> y;

        ll res = 0;
        if(k == 1) {
        	res = x + y;
		} else if(k & 1) {
            ll tmp = y / (k/2);
            ll com = min(x, tmp);
            res += com;
            x -= com;
            y -= com * (k/2);
            //cout << x << " " << y << "\n";

            if(2*y <= (k - 1)) {
                ll need = k;
                need -= 2 * y;
                y = 0;
                if(x >= need) {
                    res++;
                    x -= need;
                }
                res += x/k;
            } else {
                res += y / ((k/2)+1);
            }
        } else {
            res = (x + 2 * y) / k;
        }
                
        cout << res << "\n";
    }

 
    return 0;
}

