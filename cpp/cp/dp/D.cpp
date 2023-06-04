#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MAX (int) (1e6 + 500)
using namespace std;

vector<int> dp(1000001, MAX);
vector<int> from(1000001, -1);
unordered_map<int, int> m;
int main() { _
    int n ,x;
    cin >> n >> x;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[arr[i]] = 1;
        m.insert({arr[i], 0});
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= x; ++j) {
            if(j >= arr[i]) {
                if(dp[j - arr[i]] + 1 < dp[j]) {
                    dp[j] = dp[j - arr[i]] + 1;
                    from[j] = j - arr[i];
                }
            }
        }
    }

    if(dp[x] == MAX) cout << "-1\n";
    else {
        cout << dp[x] << "\n";
        
        int f = from[x];
        int curr = x;
        while(f != -1) {
            m[curr - f]++;
            curr = f;
            f = from[f];
        }
        m[curr]++;

        for(int i : arr) {
            cout << m[i] << " ";
        }
    } 

    return 0;
}