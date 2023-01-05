#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n = 0;
    cin >> n;
    while(n--) {
        string result = "";
        int a[7] = {0}, b[7] = {0};
        for(int i = 0; i < 7; ++i) {
            cin >> a[i];
        }

        for(int i = 0; i < 7;++i) {
            cin >> b[i];
        }

        if(a[1] == a[3] || a[1] != a[5] || b[1] == b[3] || b[1] != b[5]) {
            result.append("A");
        }

        if(a[6] != 1 || b[6] != 0) {
            result.append("B");
        }

        if(a[1] == b[1] || a[3] == b[3] || a[5] == b[5]) {
            result.append("C");
        }

        if(result.empty()) {
            cout << "None\n";
        } else {
            cout << result << "\n";
        }

    }

    return 0;
}