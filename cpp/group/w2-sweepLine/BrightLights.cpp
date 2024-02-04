#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define PI 3.1415926535897932
using namespace std;
using ll = long long int;
struct point {
    ll x, y, z;
    double angle;
    
    point(ll x, ll y, ll z) : x(x), y(y), z(z) {
        angle = atan2(y, x);
        
    }

    double dis() const {
        return pow(x, 2) + pow(y, 2);
    }

    bool operator < (const point& p) const {
        return angle == p.angle ? (dis() < p.dis()) : angle < p.angle;
    }
};

bool cmp(const point& a, const point& b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int main() { _
    int n;
    int cnt = 1;
    while(cin >> n && n > 0) {
        vector<point> ps;
        ll x, y, z;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y >> z;
            if(x == y && y == 0) {
                continue;
            }
            ps.push_back(point(x, y, z));
        }

        sort(ps.begin(), ps.end());

        // for(int i = 0; i < n; ++i) {
        //     cout << ps[i].angle << " " << ps[i].dis() << "\n";
        // }

        double curr = ps[0].angle;
        ll height = ps[0].z;
        vector<point> unvis;
        for(int i = 1; i < n; ++i) {
            if(ps[i].angle == curr) {
                if(ps[i].z <= height) {
                    unvis.push_back(ps[i]);
                }
                height = max(height, ps[i].z);
            } else {
                curr = ps[i].angle;
                height = ps[i].z;
            }
        }

        cout << "Data set " << cnt << ":\n";
        if(unvis.size() == 0) {
            cout << "All the lights are visible.\n";
        } else {
            cout << "Some lights are not visible:\n";
            sort(unvis.begin(), unvis.end(), cmp);
            for(int i = 0; i < unvis.size(); ++i) {
                cout << "x = " << unvis[i].x << ", y = " << unvis[i].y;
                if(i != unvis.size() - 1) {
                    cout << ";\n";
                } else {
                    cout << ".\n";
                }
            }
        }
        cnt++;
    }

    return 0;
}