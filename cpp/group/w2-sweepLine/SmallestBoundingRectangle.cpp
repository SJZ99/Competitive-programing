#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second
// #define double long double

using namespace std;
using ll = long long int;

const double eps = numeric_limits<double>().epsilon();
struct Point{
    double x, y;
    double operator * (Point q) { return x * q.x + y * q.y; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y - y * q.x; }
    bool operator < (Point b) { return (x == b.x) ? (y < b.y) : (x < b.x); }

    double dist(const Point& b) const {
        return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
    }
    double dist(const Point& b) {
        return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
    }
};

void convexHull(vector<Point>& ps, vector<Point>& res) {
    sort(ps.begin(), ps.end());
    res.clear();

    int n = 0;
    for(int i = 0; i < ps.size(); ++i) {
        while(n >= 2 && ((res[n - 1] - res[n - 2]) ^ (ps[i] - res[n - 2])) <= 0) {
            n--;
            res.pop_back();
        }
        res.push_back(ps[i]);
        n++;
    }

    for(int i = ps.size() - 2, n2 = n + 1; i >= 0; --i) {
        
        while(n >= n2 && ((res[n - 1] - res[n - 2]) ^ (ps[i] - res[n - 2])) <= 0) {
            n--;
            res.pop_back();
        }
        res.push_back(ps[i]);
        n++;
    }
    res.pop_back();
}

double pointToLineDist(Point& p, Point& a, Point& b) {
    if(a.dist(b) < eps) return 1e18;
    return fabs(((p - a) ^ (b - a))) / (a.dist(b));
}

double orthographicProjection(Point& a, Point& b, Point& c, Point& d) {
    return fabs((b - a) * (d - c)) / (c.dist(d));
}

int main() { _
    int n;
    while(cin >> n && n > 0) {
        vector<Point> ps(n);
        vector<Point> res;
        res.reserve(30);
        for(int i = 0; i < n; ++i) {
            cin >> ps[i].x >> ps[i].y;
        }

        convexHull(ps, res);

        if(res.size() <= 2) {
            cout << "0.0000\n";
            continue;
        }

        // right, left, top, bottom
        int r = 0, l = 1, t = 1, b = 0;
        int len = res.size();
        double minn = 1e20;
        while(pointToLineDist(res[t], res[0], res[1]) < pointToLineDist(res[(t + 1) % len], res[0], res[1])) {
            t++;
        }
        l = t;
        for(b = 0; b < len; ++b) {
            int bp1 = (b + 1) % len;

            // rotate top
            double curr = pointToLineDist(res[t], res[b], res[bp1]), temp;
            int tp1 = (t + 1) % len;
            while((temp = pointToLineDist(res[tp1], res[b], res[bp1])) > curr) {
                curr = temp;
                t = tp1;
                tp1 = (t + 1) % len;
            }

            // rotate right
            int rp1 = (r + 1) % len;
            while(r != t && ((res[rp1] - res[r]) * (res[bp1] - res[b])) >= 0) {
                r = rp1;
                rp1 = (r + 1) % len;
            }

            // rotate left
            int lp1 = (l + 1) % len;
            while(l != b && ((res[lp1] - res[l]) * (res[bp1] - res[b])) <= 0) {
                l = lp1;
                lp1 = (l + 1) % len;
            }

            // calculate distance
            double area = pointToLineDist(res[t], res[b], res[bp1]) * orthographicProjection(res[l], res[r], res[b], res[bp1]);
            minn = min(minn, area);
        }

        minn *= 10000.0;
        minn = round(minn) / 10000.0;
        cout << fixed << setprecision(4) << minn << "\n";
    }

    return 0;
}