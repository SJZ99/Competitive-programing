#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
char arr[10000001];

int main() { _
    int n = 0;
    cin >> n;

    int from, to;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> from >> to;
        for(int j = from; j < to; ++j) {
            if(arr[j] == 0) {
                cnt++;
                arr[j] = 1;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}