#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define PI 3.141592653589793

const double eps = numeric_limits<double>().epsilon();

struct Range {
    double low, high;

    Range(ll x, ll y, ll d) {
        double a1 = atan2(y, x);
        double a2 = asin(double(d) / sqrt(x*x + y*y));
        low = a1 - a2;
        high = a1 + a2;
    }

    Range(double l, double h) {
        low = l;
        high = h;
    }

    bool operator < (Range& a) {
        return high < a.high;
    }
};

int main() { _
    int tc;
    cin >> tc;
    while(tc--) {
        int n, d;
        cin >> n >> d;
        vector<Range> rs;
        rs.reserve(n);
        ll x, y;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            
            if(x*x + y*y <= d*d) continue;

            Range curr = Range(x, y, d);
            rs.push_back(curr);
            rs.push_back(Range(curr.low + 2 * PI, curr.high + 2 * PI));
        }

        n = rs.size();
        int hn = n/2;
        sort(rs.begin(), rs.end());

        // for(int i = 0; i < n; ++i) {
        //     cout << rs[i].low << " " << rs[i].high << "\n";
        // }

        ll res = hn;
        double curr = 0;

        for(int i = 0; i < hn; ++i) {
            curr = rs[i].high;
            ll cnt = 1;
            for(int j = 1; j < hn; ++j) {
                int id = (i + j);
                if(curr + eps < rs[id].low) {
                    curr = rs[id].high;
                    cnt++;
                }
            }
            // cout << cnt << "\n";
            res = min(cnt, res);
        }
        cout << res << "\n";
    }
    return 0;
}