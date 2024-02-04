#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef struct point {
    double x;
    double y;

    struct point operator-(struct point p) {
        return point { x - p.x, y - p.y };
    }
} Point;

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

bool isOnSegment(Point a, Point b, Point p) {
    double distance = crossProduct(p - a, b - a) / dot(b - a, b - a);

    double ap_ab = dot(p - a, b - a);
    double bp_ba = dot(p - b, a - b);

    if(ap_ab >= 0 && bp_ba >= 0 && distance <= 1e-7) return true;
    return false;

}

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Point vec1 = {x2 - x1, y2 - y1};
        Point vec2 = {x4 - x3, y4 - y3};

        double cross1 = crossProduct(vec1, {x3 - x1, y3 - y1});
        double cross2 = crossProduct(vec1, {x4 - x1, y4 - y1});

        double cross3 = crossProduct(vec2, {x1 - x3, y1 - y3});
        double cross4 = crossProduct(vec2, {x2 - x3, y2 - y3});

        double r1 = cross1 * cross2;
        double r2= cross3 * cross4;

        if(r1 < 0 && r2 < 0) cout << "YES\n";
        else if(r1 > 0 || r2 > 0) cout << "NO\n";
        else if(isOnSegment({x1, y1}, {x2, y2}, {x3, y3}) || isOnSegment({x1, y1}, {x2, y2}, {x4, y4})) cout << "YES\n";
        else if(isOnSegment({x3, y3}, {x4, y4}, {x1, y1}) || isOnSegment({x3, y3}, {x4, y4}, {x2, y2})) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}