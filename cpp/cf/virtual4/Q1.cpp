#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int tc;
    cin >> tc;
    
    while(tc--) {
        int r, c;
        cin >> r >> c;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int out1 = 4, out2 = 4;
        if(x1 == 1) out1--;
        if(x1 == r) out1--;
        if(y1 == 1) out1--;
        if(y1 == c) out1--;

        if(x2 == 1) out2--;
        if(x2 == r) out2--;
        if(y2 == 1) out2--;
        if(y2 == c) out2--;

        cout << min(out1, out2) << "\n";

    }

    return 0;
}