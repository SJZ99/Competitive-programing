#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

double distance(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() { _
    double x1, y1, r1;
    double x2, y2, r2;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    double vecX, vecY;
    vecX = x1 - x2;
    vecY = y1 - y2;

    double dis = distance(vecX, vecY);

    double px1, py1;
    px1 = x2 + (vecX * r2 / dis);
    py1 = y2 + (vecY * r2 / dis);


    vecX = -vecX;
    vecY = -vecY;

    double px2, py2;
    px2 = x1 + (vecX * r1 / dis);
    py2 = y1 + (vecY * r1 / dis);

    double rad = distance(px1 - px2, py1 - py2) / 2;

    cout << fixed << setprecision(11) << (px1 + px2) / 2 << " " << (py1 + py2) / 2 << " " << rad << "\n";

    return 0;
}