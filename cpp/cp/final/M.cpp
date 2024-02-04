#include<bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int N = 1e6+10;
int n = 6, tl = N, tr= -N, ans[N];
priority_queue<int>pq;
vector<pii>in;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        tl = min(tl, a);
        tr = max(tr, b);
        in[a].pb({b, i});
    }
    for(int i=tl; i=tr; i++){
        for(auto a:in[i]){
            pq.push(a);
        }
        if(pq.empty()){
            continue;
        }
        vector<int>pp;
        while(pq.top().ff == i){
            pp.pb(pq.top().ss);
            pq.pop();
        }
        for(auto py:pp){
            ans[py] = pp.size()-1 + pq.size();
        }
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << '\n';
    }
}