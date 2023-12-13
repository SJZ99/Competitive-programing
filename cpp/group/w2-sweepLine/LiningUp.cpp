#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define PI 3.141592653589793
#define X first
#define Y second

using namespace std;
using ll = long long int;
using point = pair<ll, ll>;

int main() { _
    int tc;
    cin >> tc;
    cin.ignore(); // ignore new line
    cin.ignore();

    while(tc--) {

        string in;
        getline(cin, in);
        ll a, b;
        vector<point> ps;
        vector<point> ps2;
        ll origin = 0;
        while(in.size() > 1) {
            sscanf(in.c_str(), "%lld %lld", &a, &b);
            ps.push_back({a, b});
            getline(cin, in);
        }
        ps2 = ps;

        ll maxx = 0;
        for(int i = 0; i < ps.size(); ++i) {

            map<double, ll> m;
            for(int j = 0; j < ps2.size(); ++j) {
                if(ps2[j].Y - ps[i].Y == 0 && ps2[j].X - ps[i].X == 0) continue;
                double degree = atan2(double(ps2[j].Y - ps[i].Y), double(ps2[j].X - ps[i].X)) * 180 / PI;
                m[degree]++;
            }

            for(auto p : m) {
                maxx = max(maxx, p.second);
            }
        }
        cout << maxx + 1 << "\n";

        if(tc >= 1) {
            cout << "\n";
        }
    }
    return 0;
}