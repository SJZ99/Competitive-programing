#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    ofstream out;
    out.open("./input/dimension_100_2.txt");

    srand(time(nullptr));
    int n = 1000;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            ll xi = floor(rand() / (RAND_MAX + 1.0) * 200 - 50);
            out << xi << " ";
        }
        out << "\n";
    }

    return 0;
}