#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define R 6378.0
#define PI 3.14159265358979323

const double eps = numeric_limits<double>().epsilon();

int main() { _
    unordered_map<string, int> hm;

    string s1;
    int cnt = 0;
    vector<pair<double, double>> ps;
    vector<vector<ll>> dis;

    double a, b;
    while(cin >> s1 && s1 != "#") {
        hm[s1] = cnt;
        cnt++;
        cin >> a >> b;
        ps.push_back({a, b});
    }
    int n = ps.size();
    dis = vector<vector<ll>>(n, vector<ll>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            double lat1 = ps[i].first * PI / 180.0;
            double lon1 = ps[i].second * PI / 180.0;

            double lat2 = ps[j].first * PI / 180.0;
            double lon2 = ps[j].second * PI / 180.0;

            double x1 = cos(lat1) * cos(lon1) * R;
            double y1 = cos(lat1) * sin(lon1) * R;
            double z1 = sin(lat1) * R;

            double x2 = cos(lat2) * cos(lon2) * R;
            double y2 = cos(lat2) * sin(lon2) * R;
            double z2 = sin(lat2) * R;

            double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2)) + eps;

            dis[i][j] = dis[j][i] = (ll) round(2 * R * asin(d / (2 * R)) + eps);
        }
    }

    string s2;
    while(cin >> s1 >> s2 && s1 != "#" && s2 != "#") {
        cout << s1 << " - " << s2 << "\n";
        if(hm.find(s1) == hm.end() || hm.find(s2) == hm.end()) {
            cout << "Unknown\n";
        } else {
            int a = hm[s1];
            int b = hm[s2];
            cout << dis[a][b] << " km\n";
        }
    }

    return 0;
}