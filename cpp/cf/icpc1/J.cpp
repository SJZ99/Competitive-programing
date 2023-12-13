#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#define int long long
using namespace std;
string str[20];
signed main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 987654321;
        int n, m; cin >> n >> m;
        for(int i=0; i<m; i++) cin >> str[i]; // bitstring
        
        bitset<501> finalState;

        for(int i = 0; i < n; ++i) {
            finalState.set(i);
        }
        // cout << finalState << "\n";
    
        // check each '1' place
        bitset<501> s[20];
        for(int i=0; i<m; i++){
            for(int j=0; j<str[i].size(); j++){
                s[i][j] = str[i][j] == '1';
            }
        }
        // for(int i=0; i<m; i++){
        //     cout << s[i] << '\n';
        // }
        
        int lim = 1<<m+1;
        for(int i=0; i<lim; i++){
            bitset<501> now;
            int cnt = 0;
            for(int j=0, ii=i; ii; j++, ii>>=1){
                if(ii&1){
                    cnt++;
                    now |= s[j];
                }
            }
            // cout << now << ' ' << i << '\n';
            if((now ^ finalState) == 0){
                ans = min(ans, cnt);
            }
        }
        cout << (ans == 987654321 ? -1 : ans) << '\n';
 
 
    }
}