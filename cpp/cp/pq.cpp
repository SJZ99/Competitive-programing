#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define int long long int

using namespace std;

signed main() { _
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int temp;
    while(n--) {
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0;
    int curr = 0;
    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        // cout << curr << " " << pq.top() << "\n";
        if(!pq.empty()) {
            sum += (curr + pq.top());
            curr += pq.top();
            pq.pop();
            pq.push(curr);
        }
    }

    cout << sum << "\n";

    return 0;
}