#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int s1, s2, r, k, x;
    cin >> s1 >> s2 >> r >> k >> x;

    int closest = -1;
    int distance = INT_MAX;
    int cnt1, cnt2;
    int temp = 0;
    for(int i = 0; i <= r; ++i) {
        for(int j = 0; j <= r - i; ++j) {
            temp = x + s1 * i - s2 * j;
            if(temp <= k) {
                if(k - temp < distance) {
                    distance = k - temp;
                    cnt1 = i;
                    cnt2 = j;
                    closest = temp;
                }
            }
        }
    }
    cout << cnt1 << " " << cnt2 << " " << closest << "\n";
    return 0;
}