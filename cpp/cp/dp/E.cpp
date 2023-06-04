#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define MAX 1000000
using namespace std;

int dp[MAX + 5];
int main() { _
    int n, x;
    cin >> n >> x;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < x; i++){
        if(dp[i] != 0) {
            for (int j = 0; j < n; j++){
                if(i + arr[j] <= MAX) {
                    dp[i + arr[j]] += dp[i];
                    dp[i + arr[j]] %= int(1e9 + 7);
                }
            }
        }
    }
    cout << dp[x] << "\n";


    return 0;
}