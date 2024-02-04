#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;

    long long int a, b;

    while(t--) {
        cin >> a >> b;

        int mul = 1;
        long long int res = 0;

        while(b != 0) {
            res += ((a % 1073676287) * ((b & 1) * (mul % 1073676287)) % 1073676287);
            res %= 1073676287;
            b >>= 1;
            mul = ((mul % 1073676287) * 2) % 1073676287;
        }
        cout << res << "\n";
    }

    return 0;
}