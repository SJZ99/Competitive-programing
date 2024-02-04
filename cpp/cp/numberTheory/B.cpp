#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define N 1073676287

using namespace std;
using ll = unsigned long long int;

int main() { _
    int t;
    cin >> t;

    int m, n;
    while(t--) {
        cin >> m >> n;
        ll mul = n;
        ll res = 1;

        while(m != 0) {
            if(m & 1) {
                res = ((res % N) * (mul % N)) % N;
            }
            
            mul = ((mul % N) * (mul % N)) % N;
            m >>= 1;
        }
        cout << (res % N) << "\n";
    }

    return 0;
}