#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    unordered_map<int, int> f;

    int dp1 = 1, dp2 = 1;
    int temp = 2;
    f[1] = 1;
    for(; temp < 1e6 + 10; dp1 = dp2, dp2 = temp) {
        temp = dp1 + dp2;
        f[dp1] = dp2;
    }

    int n;
    cin >> n;
    vector<int> in(n + 1);
    unordered_map<int, int> index;

    int one1 = -1, one2 = -1;
    for(int i = 1; i <= n; ++i) {
        cin >> temp;
        index[temp] = i;
        in[i] = temp;
        if(temp == 1) {
            if(one1 == -1) {
                one1 = i;
            } else if(one2 == -1) {
                one2 = i;
            }
        }
    }

    if(one1 != -1 && one2 != -1) {
        cout << one1 << " " << one2 << "\n";
    } else {
        bool found = false;
        for(int i = 1; i <= n; ++i) {
            if(f.find(in[i]) != f.end()) {
                if(index.find(f[in[i]]) != index.end()) {
                    cout << i << " " << index[f[in[i]]] << "\n";
                    found = true;
                    break;
                }
            }
        }

        if(!found) cout << "impossible\n";
    }
    return 0;
}