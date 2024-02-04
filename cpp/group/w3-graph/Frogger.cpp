#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
using point = pair<int, int>;

#define X first
#define Y second

struct edge {
    int i, j;
    double dis;
};

inline double dis(vector<point>& ps, int i, int j) {
    return sqrt(pow(ps[i].X - ps[j].X, 2) + pow(ps[i].Y - ps[j].Y, 2));
}

int main() { _
    int n;
    int cnt = 1;
    while(cin >> n && n > 0) {
        vector<point> ps(n);
        cin >> ps[0].X >> ps[0].Y >> ps[n - 1].X >> ps[n - 1].Y;

        for(int i = 1; i < n - 1; ++i) {
            cin >> ps[i].X >> ps[i].Y;
        }

        vector<edge> es;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                es.push_back({i, j, dis(ps, i, j)});
            }
        }

        int elen = es.size();
        vector<double> minmax(n, 1e20);
        minmax[0] = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < elen; ++j) {
                auto& e = es[j];
                if(minmax[e.i] < 1e20) {
                    double t = max(minmax[e.i], e.dis);
                    minmax[e.j] = min(minmax[e.j], t);
                }
            }
        }

        // for(int i = 0; i < n; ++i) {
        //     cout << minmax[i] << " ";
        // }
        // cout << "\n";

        // if(cnt != 1) cout << "\n";
        cout << "Scenario #" << cnt++ << "\n";
        cout << "Frog Distance = ";
        cout << fixed << setprecision(3) << minmax[n - 1] << "\n\n";
    }

    return 0;
}