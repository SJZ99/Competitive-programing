#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;

struct Point{
    double x, y;
    double operator * (Point q) { return x * q.x + y * q.y; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y - y * q.x; }
    bool operator < (Point b) { return x == b.x ? y < b.y : x < b.x; }

    double dist(const Point& b) const {
        return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
    }
};

void convexHull(vector<Point>& ps, vector<Point>& res) {
    sort(ps.begin(), ps.end());
    res.clear();

    int n = 0;
    for(int i = 0; i < ps.size(); ++i) {
        while(n >= 2 && ((res[n - 1] - res[n - 2]) ^ (ps[i] - res[n - 2])) < 0) {
            n--;
            res.pop_back();
        }
        res.push_back(ps[i]);
        n++;
    }

    for(int i = ps.size() - 2, n2 = n + 1; i >= 0; --i) {
        
        while(n >= n2 && ((res[n - 1] - res[n - 2]) ^ (ps[i] - res[n - 2])) < 0) {
            n--;
            res.pop_back();
        }
        res.push_back(ps[i]);
        n++;
    }
    res.pop_back();
}

double pointToLineDist(const Point& p, const Point& a, const Point& b) {
    return fabs((p - a) ^ (b - a)) / a.dist(b);
}

int main() { _
    int n;
    while(cin >> n && n > 0) {
        vector<Point> ps(n);
        vector<Point> res;
        res.reserve(30);
        for(int i = 0; i < n; ++i) {
            cin >> ps[i].first >> ps[i].second;
        }
        convexHull(ps, res);

        if(res.size() <= 2) {
            cout << "0.0000\n";
            continue;
        }

        // right, left, top, bottom
        int r = 0, l = 0, t = 0, b = 0;
        for(int i = 0; i < res.size(); ++i) {
            if(res[i].x > res[r].x) r = i;
            if(res[i].x < res[l].x) l = i;
            if(res[i].y > res[t].y) t = i;
        }

        int len = res.size();
        for(b = 0; b < len; ++b) {
            int bp1 = (b + 1) % len;
            // rotate top
            double curr = pointToLineDist(res[t], res[b], res[bp1]);
            double temp;
            int tp1 = (t + 1) % len;
            while((temp = pointToLineDist(res[bp1], res[b], res[bp1])) > curr) {
                curr = temp;
                t = tp1;
                tp1 = (t + 1) % len;
            }

            // rotate right
            int rp1 = (r + 1) % len;
            while((res[rp1] - res[r]) ^ (res[bp1] - res[b]) > 0) {
                r = rp1;
                rp1 = (r + 1) % len;
            }

            // rotate left
            int lp1 = (l + 1) % len;
            while(() ^ ())
        }
    }

    return 0;
}