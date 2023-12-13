#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

void mul(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    int n = c.size();
    for(int i = 0; i < n; ++i) {
        c[i] = b[a[i]];
    }
}

// a^n * b
void qpow(vector<int>& a, vector<int>& b, ll n) {

    vector<int> a2(a.size());
    vector<int> c(b.size());
    while(n != 0) {
        if(n & 1) {
            mul(a, b, c);
            b = c;
        }
        mul(a, a, a2);
        a = a2;
        n = (n >> 1);
    }
}

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        ll n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; ++i) {
            b[i] = i;
        }

        for(int i = 0; i < n / 2; ++i) {
            a[i] = i * 2;
        }

        for(int i = 0; i < n / 2; ++i) {
            a[i + n / 2] = i * 2 + 1;
        }

        qpow(a, b, k);
        for(int i = 0; i < n; ++i) {
            cout << b[i] + 1;
            if(i != n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}