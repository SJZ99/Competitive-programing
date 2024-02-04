#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Point {
    int x, y;
};

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        Point ps[4];
        for(int i = 0; i < 4; ++i) {
            cin >> ps[i].x >> ps[i].y;
        }

        if(ps[0].x != ps[1].x) {
            cout << abs(ps[0].x - ps[1].x) * abs(ps[0].x - ps[1].x) << "\n";
        } else {
            cout << abs(ps[0].y - ps[1].y) * abs(ps[0].y - ps[1].y) << "\n";
        }
    }  

    return 0;
}