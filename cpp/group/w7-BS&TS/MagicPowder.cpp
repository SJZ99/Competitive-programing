#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int req[1001];
int poss[1001];

bool f(int num, int n, int k) {
    for(int i = 0; i < n; ++i) {
        int tar = num * req[i];
        if(tar > poss[i] && tar <= poss[i] + k) {
            k -= tar - poss[i];
        } else if(tar > poss[i] + k) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> req[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> poss[i];
    }

    int l = 0, r = 2010, m;

    while(r - l > 1) {
        m = l + (r - l) / 2;
        if(f(m, n, k)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
    return 0;
}
