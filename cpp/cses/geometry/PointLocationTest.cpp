#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Point{
    ll x, y;
    double operator * (Point q) { return x * q.x + y * q.y; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y - y * q.x; }
    bool operator < (Point b) { return x == b.x ? y < b.y : x < b.x; }
};


int main() { _
    int n;
    cin >> n;

    while(n--) {
        ll x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point vec = {x2 - x1, y2 - y1};
        Point vec2 = {x3 - x1, y3 - y1};
        double cross = vec ^ vec2;

        if(abs(cross) < numeric_limits<double>::epsilon()) {
            cout << "TOUCH\n";
        } else if(cross > 0) {
            cout << "LEFT\n";
        } else {
            cout << "RIGHT\n";
        }
    }

    return 0;
}