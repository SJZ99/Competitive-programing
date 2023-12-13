#include<bits/stdc++.h>
using namespace std;
int n, q, a[5010];
int main(){
    cin >> n >> q;
    for(int i=0; i<q; i++){
        int c, b;
        cin >> c >> b;
        a[b]++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            ans++;
        }
    }
    cout << ans << '\n';
}