#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        bool fl = 0;
        int len = str.size(), num = 0;
        priority_queue<int>pq;
        for(int j=0; j<len; j++){
            if(str[j] > '9'){
                pq.push(num);
                num = 0;
                continue;
            }
            else {
                fl = 1;
                num = num*10 + str[j]-'0';
            }
        }
        if(str[len-1] <='9')
            pq.emplace(num);
        if(!fl){
            cout << "cca9f340bde65636\n";
            continue;
        }
        int ans = pq.top();
        pq.pop();
        while(pq.size()){
            int x = pq.top();
            ans ^= x;
            pq.pop();
        }
        cout << ans << '\n';
    }
}