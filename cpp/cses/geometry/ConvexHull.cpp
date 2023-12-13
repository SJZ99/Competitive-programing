#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Point{
    long long int x, y;
    double operator * (Point q) { return x * q.x + y * q.y; }
    Point operator + (Point b) { return {x + b.x, y + b.y}; }
    Point operator - (Point b) { return {x - b.x, y - b.y}; }
    double operator ^ (Point q) { return x * q.y * 1.0 - y * q.x * 1.0; }
    bool operator < (Point b) { return x == b.x ? y < b.y : x < b.x; }
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

int main() { _
    int n;
    cin >> n;

    vector<Point> ps(n);
    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        ps[i] = {a, b};
    }

    vector<Point> res;
    convexHull(ps, res);

    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i].x << " " << res[i].y << "\n";
    }

    return 0;
}
