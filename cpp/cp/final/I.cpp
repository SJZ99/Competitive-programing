#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, dp[N];
vector<int>r[N];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        r[max(i, a)].push_back(abs(a-i));
    }
    // for(int i=1; i<=n; i++){
    //     for(auto x:r[i]){
    //         cout << i << ' ' << x << '\n';
    //     }
    // }
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int len = r[i].size();
        if(len == 0){
            dp[i] = dp[i-1];
            // cout  <<"ouo "<< i << ' '<< dp[i]<<'\n';
            continue;
        }
        int mx = dp[i-1];
        for(auto ll:r[i]){
            mx = max(mx, dp[i-ll-1]+1);
        }
        dp[i] = mx;
      // cout <<i<<' '<< dp[i] << '\n';
    } //cout << '\n';
    cout << n-dp[n] << '\n';
}