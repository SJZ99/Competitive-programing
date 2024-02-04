#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int n;
    cin >> n;
    if(n == 3 || n == 2) {
        cout << "NO SOLUTION\n";
    } else {
        int a = n / 2, b = n;
        if(n & 1 != 0) {
            a++;
        }
        for(int i = 1; i <= n / 2; ++i) {
            cout << a << " " << b << " ";
            a--, b--;
        }

        if(n & 1 != 0) {
            cout << a;
        }
    }


    return 0;
}