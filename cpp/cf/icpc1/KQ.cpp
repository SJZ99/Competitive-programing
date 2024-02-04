#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq;
        int temp;
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            pq.push(temp);
        }

        int res = 0;
        for(int i = 0; i < n - 1; ++i) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            res += a + b;
            pq.push(a + b);
        }
        cout << res << "\n";
    }

    return 0;
}