#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

const double eps = numeric_limits<double>().epsilon();

struct Point {
    double x, y;
    double operator * (Point q) { return x * q.x + y * q.y; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y - y * q.x; }
    bool operator < (Point b) { return x == b.x ? y < b.y : x < b.x; }

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

double pointToLineDist(Point& p, Point& a, Point& b) {
    if(a.dist(b) < eps) return 1e18;
    return fabs(((p - a) ^ (b - a))) / (a.dist(b));
}

double orthographicProjection(Point& a, Point& b, Point& c, Point& d) {
    return fabs((b - a) * (d - c)) / (c.dist(d));
}

int main() { _
    int tc;
    cin >> tc;

    int cnt = 1;
    while(tc--) {
        int n;
        cin >> n;
        vector<Point> ps;
        ps.reserve(n);

        double x, y;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            ps.push_back(Point {x, y});
            // cout << ps.back().x << " " << ps.back().y << endl;
        }

        vector<Point> ch;
        ch.reserve(n / 2);

        convexHull(ps, ch);

        // rotatary cliper
        int b = 0, t = 1, l = 1, r = 0;

        int len = ch.size();

        // cout << ch[0].x << " " << ch[0].y << "\n";

        double minn = 1e18;
        for(b = 0; b < len; ++b) {
            int bp1 = (b + 1) % len;

            // rotate top
            double curr = pointToLineDist(ch[t], ch[b], ch[bp1]), temp;
            int tp1 = (t + 1) % len;
            while((temp = pointToLineDist(ch[tp1], ch[b], ch[bp1])) > curr) {
                curr = temp;
                t = tp1;
                tp1 = (t + 1) % len;
            }

            // rotate right
            int rp1 = (r + 1) % len;
            while(r != t && ((ch[rp1] - ch[r]) * (ch[bp1] - ch[b])) >= 0) {
                r = rp1;
                rp1 = (r + 1) % len;
            }

            // rotate left
            int lp1 = (l + 1) % len;
            while(l != b && ((ch[lp1] - ch[l]) * (ch[bp1] - ch[b])) <= 0) {
                l = lp1;
                lp1 = (l + 1) % len;
            }

            //    /----/    \----\
            //   /----/      \----\
            //  /----/   or   \----\

            // double side1 = min(max(orthographicProjection(ch[b], ch[r], ch[b], ch[bp1]), orthographicProjection(ch[t], ch[l], ch[bp1], ch[b])), 
            //                     max(orthographicProjection(ch[bp1], ch[l], ch[bp1], ch[b]), orthographicProjection(ch[t], ch[r], ch[b], ch[bp1])));

            // // calculate distance
            // double area = pointToLineDist(ch[t], ch[b], ch[bp1]) * side1;
            // cout << b << " " << r << " " << t << " " << l << endl;
            // cout << pointToLineDist(ch[t], ch[b], ch[bp1]) << " " << side1 << " " << area << endl;
            // minn = min(minn, area);

            double area = pointToLineDist(ch[t], ch[b], ch[bp1]) * orthographicProjection(ch[l], ch[r], ch[b], ch[bp1]);
            minn = min(minn, area);
        }

        cout << "Swarm " << cnt << " Parallelogram Area: " << fixed << setprecision(4) << minn << "\n";
    }

    return 0;
}