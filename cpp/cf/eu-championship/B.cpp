#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

bool f(vector<int>& a, vector<int>& b, int n, int atleast) {
    vector<bool> used(a.size(), 0);
    for(int i = n - 1; i >= 0; --i) { // a
        int parn = -1;
        for(int j = n - 1; j >= 0; --j) {
            
            if(a[i] - b[j] >= atleast && !used[j]) {
                parn = j;
                break;
            }

            if(b[j] - a[i] >= atleast && !used[j]) {
                parn = j;
            }
        }
        if(parn != -1) {
            // cout << i << " " << parn << "\n";
            used[parn] = true;
        } else {
            return false;
        }
    }
    return true;
}

int main(void) { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        vector<int> a, b;
        a.reserve(n);
        b.reserve(n);

        int tmp;
        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            a.push_back(tmp);
        }

        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            b.push_back(tmp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());;

        int l = 0, r = max(b[n - 1] - a[0], a[n - 1] - b[0]) + 1, m;

        while(r - l > 1) {
            m = l + (r - l) / 2;

            // cout << m << " " << f(a, b, n, m) << "\n";
            if(f(a, b, n, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l << "\n";
    }
    return 0;
}
