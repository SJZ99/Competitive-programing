#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a;
        vector<int> b;
        a.reserve(n);
        b.reserve(n);

        a.push_back(2 * n);

        int front = 1;
        int back = 2 * n - 2;
        bool isFront = true;
        for(int i = 1; i < n; ++i) {
            if(isFront) {
                b.push_back(front++);
                a.push_back(front++);
            } else {
                a.push_back(back--);
                b.push_back(back--);
            }   
            isFront = !isFront;     
        }
        b.push_back(2 * n - 1);

        for(int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";

        for(int i : b) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}