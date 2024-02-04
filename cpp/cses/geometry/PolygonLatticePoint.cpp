#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Point{
    ll x, y;
    ll operator ^ (Point q) { return x * q.y - y * q.x; }
};

int main() { _
    int n;
    cin >> n;
    vector<Point> poly(n);
    ll x, y;
    ll internal = 0;
    ll bound = 0, area = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        Point p = {x, y};
        poly[i] = p;

        if(i > 0) {
            bound += __gcd(abs(p.x - poly[i - 1].x), abs(p.y - poly[i - 1].y));
            area += (p ^ poly[i - 1]);
        }
    }
    area += (poly[0] ^ poly[n - 1]);
    area = abs(area) / 2;
    bound += __gcd(abs(poly[0].x - poly[n - 1].x), abs(poly[0].y - poly[n - 1].y));

    // cout << (area - bound + 2) / 2 << "\n";
    internal = (ll) (area - bound / 2 + 1);
    cout << internal << " " << (ll) bound << "\n";

    return 0;
}