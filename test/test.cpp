#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int n, k;
 
bool query(int i, int j, int x){
    cout << "? " << i << " " << j << " " << x << endl;
    cout.flush();
    bool ret = 0;
    cin >> ret;
    return ret;
}
 
bool check(int x){
    int cnt = 0;
    int j = n;
    for(int i=1;i<=n;i++){
        while(!query(i, j, x)){
            j--;
            if(j <= 0) break;
        }
        if(j <= 0) break;
        cnt += j;
        //if(j != n) break;
    }
 
    return cnt < n * n - k + 1;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
 
    int l = 1, r = n * n;
 
    int ans = 1;
 
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(check(mid)) l = mid + 1;
        else ans = mid, r = mid - 1;
    }
 
    cout << "! " << ans << endl;
    cout.flush();
 
 
    return 0;
}
