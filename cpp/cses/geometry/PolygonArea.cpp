#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

using ll = long long int;

typedef struct p {
    ll x;
    ll y;

    ll cross(struct p a) {
        return x * a.y - y * a.x;
    }
} Point;


int main() { _
    int n;
    cin >> n;

    vector<Point> ps(n);
    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        ps[i] = {a, b};
    }

    ll res = 0;
    for(int i = 0; i < n; ++i) {
        int index = (i + 1) % n;
        res += ps[i].cross(ps[index]);
    }

    cout << abs(res) << "\n";
    return 0;
}