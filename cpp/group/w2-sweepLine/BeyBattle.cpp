#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<ll, ll>;

ll dis(point& a, point& b) {
    return max(abs(a.X - b.X), abs(a.Y - b.Y));
}

int main() { _
    int n;
    while(cin >> n) {
        vector<point> ps(n);
        for(int i = 0; i < n; ++i) {
            cin >> ps[i].X >> ps[i].Y;
        }
        sort(ps.begin(), ps.end());

        ll minn = LLONG_MAX;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(ps[i].X + minn < ps[j].X) {
                    break;
                }
                double d = dis(ps[i], ps[j]);
                if(d < minn) {
                    minn = d;
                }
            }
        }

        cout << minn << "\n";
    }

    return 0;
}