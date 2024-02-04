#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define X first
#define Y second

using namespace std;
using ll = long long int;

using point = pair<int, int>;

double dis(const point& a, const point& b) {
    return hypot(a.X - b.X, a.Y - b.Y);
}

int main() { _
    double x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double midx = min(x2, max(x1, x));
    double midy = min(y2, max(y1, y));
    // cout << midx << " " << midy << endl;

    cout << fixed << setprecision(3) << hypot(midx - x, midy - y) << "\n";
    return 0;
}