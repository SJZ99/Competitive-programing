#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<double, double>;

double dis(point& a, point& b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

int main() { _
    int n;
    while(cin >> n && n > 0) {
        vector<point> ps(n);
        for(int i = 0; i < n; ++i) {
            cin >> ps[i].X >> ps[i].Y;
        }
        sort(ps.begin(), ps.end());

        double minn = 1e20;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(ps[i].X + minn < ps[j].X) {
                    break;
                }
                double d = dis(ps[i], ps[j]);
                minn = min(minn, d);
            }
        }

        if(minn > 10000) {
            cout << "INFINITY\n";
        } else {
            cout << fixed << setprecision(4) << minn << "\n";
        }
    }

    return 0;
}