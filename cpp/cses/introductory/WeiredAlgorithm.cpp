#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    
    ll in;
    cin >> in;

    while(in != 1) {
        cout << in << " ";
        if(in % 2 == 0) {
            in /= 2;
        } else {
            in *= 3;
            in++;
        }
    }
    cout << "1";
    return 0;
}