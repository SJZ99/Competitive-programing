#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ps;
        int x, y;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            ps.push_back({x, y});
        }

        sort(ps.begin(), ps.end(), greater<pair<int, int>>());

        int pre = 0;
        double res = 0;
        for(int i = 1; i < ps.size(); ++i) {
            if(ps[i].second > ps[i - 1].second && ps[i].second > pre) {
                double len = sqrt(pow(ps[i].first - ps[i - 1].first, 2) + pow(ps[i].second - ps[i - 1].second, 2));
                len *= double(ps[i].second - pre) / double(ps[i].second - ps[i - 1].second);
                res += len;
                pre = ps[i].second;
            }
        }
        cout << fixed << setprecision(2) << res << "\n";
    } 

    return 0;
} 