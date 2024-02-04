#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;
    cin.ignore();

    while(tc--) {
        int n;
        cin >> n;
        cin.ignore();

        char b[100001] = {0};
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        cin.ignore();

        char tmp;
        int zero = 0, one = 0;
        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            // cout << tmp << " " << b[i] << endl;
            if(tmp != b[i]) {
                if(tmp == '1') {
                    one++;
                } else {
                    zero++;
                }
            }
        }
        cin.ignore();

        cout << max(zero, one) << "\n";
    }

    return 0;
}