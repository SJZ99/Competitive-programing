#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<double, double>;

ll dis(point& a, point& b) {
    return pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2);
}

int main() { _
    int n;
    cin >> n;
    vector<point> ps(n);
    for(int i = 0; i < n; ++i) {
        cin >> ps[i].X >> ps[i].Y;
    }
    sort(ps.begin(), ps.end());

    ll minn = LLONG_MAX;
    double sq = sqrt(minn);
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(ps[i].X + sq < ps[j].X) {
                break;
            }

            ll d = dis(ps[i], ps[j]);
            if(d < minn) {
                minn = d;
                sq = sqrt(minn);
            }
        }
    }

    cout << minn << "\n";
    return 0;
}