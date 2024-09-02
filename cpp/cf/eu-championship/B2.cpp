#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

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

        int maxx = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(a[n - 1] >= b[i]) {
                int minn = INT_MAX;
                for(int j = 0; j < n; ++j) {
                    minn = min(abs(b[(i - j + n) % n] - a[n - 1 - j]), minn);
                }

                // for(int j = i + 1; j < n; ++j) {
                //     minn = min(abs(b[(i - j + n) % n] - a[j - i - 1]), minn);
                // }

                maxx = max(maxx, minn);
            }
        }

        for(int i = n - 1; i >= 0; --i) {
            if(b[n - 1] >= a[i]) {
                int minn = INT_MAX;
                for(int j = 0; j < n; ++j) {
                    minn = min(abs(a[(i - j + n) % n] - b[n - 1 - j]), minn);
                }

                // for(int j = i + 1; j < n; ++j) {
                //     minn = min(abs(a[(i - j + n) % n] - b[j - i - 1]), minn);
                // }
                maxx = max(maxx, minn);
            }
        }

        cout << maxx << "\n";
    }
    return 0;
}
