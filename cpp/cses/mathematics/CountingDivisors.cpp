#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) { _
    int tc;
    cin >> tc;
    while(tc--) {
        int x;
        cin >> x;

        int cnt = 0;
        for(int i = 1; i < sqrt(x); ++i) {
            if(x % i == 0) {
                cnt += 2;
            }
        }

        int rt = (int) sqrt(x);
        if(rt * rt == x) {
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}
