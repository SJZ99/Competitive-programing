#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    ofstream out;
    out.open("./input/point_5000.txt");
    srand(time(nullptr));

    for(int i = 0; i < 5000; ++i) {
        ll x = rand() / (RAND_MAX + 1.0) * INT_MAX * 2 + INT_MIN;
        ll y = rand() / (RAND_MAX + 1.0) * INT_MAX * 2 + INT_MIN;

        out << x << " " << y << "\n";
    }


    // for(ll i = 10000000; i < 170000000; i += 10000003) {
    //     cout << 10 + 4 * i << " " << 5 + 23 * i << "\n";
    // }
    return 0;
}