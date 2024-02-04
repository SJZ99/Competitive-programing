#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;
        int ra, ca, rb, cb;
        cin >> n >> m >> ra >> ca >> rb >> cb;

        if(rb <= ra) {
            cout << "Draw\n";
        } else if((rb - ra) % 2 != 0) { // a
            ra++;
            bool find = false;
            for(int off = -1; off <= 1; ++off) {
                ca += off;
                int k = (rb - ra) >> 1;
                if(ca == cb) {
                    cout << "Alice\n";
                    find = true;
                    break;
                } else if(ca < cb && m - ca - 1 < k) {
                    cout << "Alice\n";
                    find = true;
                    break;
                } else if(ca > cb && ca - 2 < k) {
                    cout << "Alice\n";
                    find = true;
                    break;
                }
                ca -= off;
            }

            if(!find) cout << "Draw\n";

        } else { // b
            int k = (rb - ra) >> 1;
            if(ca == cb) {
                cout << "Bob\n";
            } else if(ca < cb && cb - 2 < k) {
                cout << "Bob\n";
            } else if(ca > cb && m - cb - 1 < k) {
                cout << "Bob\n";
            } else {
                cout << "Draw\n";
            }
        }
    }

    return 0;
}