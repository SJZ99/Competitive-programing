#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;

        int res = 0;
        int dis = 0;
        bool found = false;
        for(int i = l; i <= r; ++i) {
            int temp = i;
            int maxx = 0, minn = 9;
            while(temp > 0) {
                int digi = temp % 10;
                temp /= 10;

                maxx = max(maxx, digi);
                minn = min(minn, digi);
                if((maxx - minn) >= dis) {
                    dis = (maxx - minn);
                    res = i;
                    if(dis == 9) found = true;
                }
            }
            if(found) {
                break;
            }
        }
        cout << res << "\n";
    }

    return 0;
}