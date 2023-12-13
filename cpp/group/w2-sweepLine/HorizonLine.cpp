#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n, m;
    while(cin >> n) {
        vector<pair<double, double>> f(n);
        double curr = 0;
        double len = 0;
        for(int i = 0; i < n; ++i) {
            cin >> f[i].second >> len;
            f[i].first = curr;
            curr += len;
        }

        cin >> m;
        vector<pair<double, double>> g(m);
        curr = 0;
        for(int i = 0; i < m; ++i) {
            cin >> g[i].second >> len;
            g[i].first = curr;
            curr += len;
        }

        sort(f.begin(), f.end());
        sort(g.begin(), g.end());

        int p1 = 0, p2 = 0;
        double res = INT_MAX;
        while(p1 < f.size() || p2 < g.size()) {
            // cout << p1 << " " << p2 << "\n";
            res = min(res, max(f[p1].second, g[p2].second));

            if(p1 + 1 < f.size() && p2 + 1 < g.size()) {
                auto nf = f[p1 + 1];
                auto ng = g[p2 + 1];
                if(nf.first > ng.first) {
                    p2++;
                } else if(nf.first < ng.first) {
                    p1++;
                } else {
                    p1++;
                    p2++;
                }
            } else if(p1 + 1 < f.size()) {
                p1++;
            } else if(p2 + 1 < g.size()) {
                p2++;
            } else {
                break;
            }
        }
        res *= 1000;
        res = round(res);
        res /= 1000;

        cout << fixed << setprecision(3) << res << "\n";
    }

    return 0;
}