#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
struct Point{
    ll x, y;
    double operator * (Point q) { return x * q.x * 1.0 + y * q.y * 1.0; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y * 1.0 - y * q.x * 1.0; }
    bool operator < (Point b) { return x == b.x ? y < b.y : x < b.x; }

    bool isOnSegment(Point a, Point b) {
        if(abs((*this - a) ^ (b - a)) > 1e-8) {
            return false;
        }
        return (*this - a) * (b - a) >= 0 && (*this - b) * (a - b) >= 0;
    }

    void swap(Point& p) {
        int t = x;
        x = p.x;
        p.x = t;

        t = y;
        y = p.y;
        p.y = t;
    }
};

// {-1, 0, 1}: {outside, boundary, inside} 
int inPoly(vector<Point>& poly, Point p) {
    int n = poly.size();

    int farX = (int) 1e9 + 10;
    Point r = {farX, p.y};

    int intersection = 0;
    for(int i = 0; i < n; ++i) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];

        if(p2.y > p1.y) p1.swap(p2);

        // at segment
        if(p.isOnSegment(p1, p2)) return 0;

        if(p1.y != p2.y && p2.isOnSegment(p, r)) {
            intersection++;
        } else {
            // rays intersection
            double r1 = ((p2 - p1) ^ (p - p1)) * ((p2 - p1) ^ (r - p1));
            double r2 = ((p - r) ^ (p2 - r)) * ((p - r) ^ (p1 - r));

            if(r1 < 0 && r2 < 0) intersection++;
        }
    }
    return (intersection & 1) ? 1 : -1;
}

int main() { _
    
    int n, m;
    cin >> n >> m;

    int x, y;
    vector<Point> poly(n);

    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        poly[i] = {x, y};
    }

    while(m--) {
        cin >> x >> y;
        Point p = {x, y};

        int res = inPoly(poly, p);

        if(res > 0) {
            cout << "INSIDE\n";
        } else if(res == 0) {
            cout << "BOUNDARY\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
    return 0;
}