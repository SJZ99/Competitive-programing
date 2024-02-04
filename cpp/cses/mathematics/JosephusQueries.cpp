
#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

unsigned long long int kill(long long int n, long long int k) {
    if(n == 1 && k == 1) return 1;
    if(n % 2 != 0) {
        unsigned long long int ki = kill(n - 1, k - 1);
        ki += 2;
        while(ki > n) ki -= n;
        return ki;
    } else if(n / 2 >= k) {
        return 2 * k;
    } else {
        unsigned long long int res = 2 * kill(n / 2, k - n / 2) - 1;
        while(res > n) res -= n;
        return res;
    }
}

int main() { _
    int q;
    cin >> q;

    while(q--) {
        long long int n, k;
        cin >> n >> k;

        cout << kill(n, k) << "\n";
    }

    return 0;
}