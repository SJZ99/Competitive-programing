#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<ll, ll>;

double dis(point& a, point& b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

int main() { _
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        vector<point> ps(n);
        for(int i = 0; i < n; ++i) {
            cin >> ps[i].X >> ps[i].Y;
        }
        sort(ps.begin(), ps.end());

        double minn = 1e20;
        point *a, *b;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(ps[i].X + minn < ps[j].X) {
                    break;
                }
                double d = dis(ps[i], ps[j]);
                if(d < minn) {
                    minn = d;
                    a = &ps[i];
                    b = &ps[j];
                }
            }
        }

        double x = double(a->X + b->X) / 2;
        double y = double(a->Y + b->Y) / 2;
        cout << fixed << setprecision(3) << x << " " << y << "\n";
        if(tc != 0) {
            cout << "\n";
        }
    }

    return 0;
}