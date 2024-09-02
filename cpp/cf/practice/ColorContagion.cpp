#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
 
const int maxn = 2e5+5;

const ll mod = 998244353;

ll fact[maxn];

ll child[maxn];

vector<int> g[maxn];

ll res = 1;

ll fpow(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    } 
    return ret;
}

// calc children number
int chilrenNumber(int x, int from) {
    child[x] = 0;
    for(int nei : g[x]) {
        if(nei != from) {
            child[x] += chilrenNumber(nei, x);
        }
    }

    return child[x] + 1;
}

void dfs(int curr, int from) {
    res *= fact[child[curr]];
    // cout << "* " << child[curr] << "!\n";
    res %= mod;
    for(int nei : g[curr]) {
        // cout << "/ " << child[curr] << "!\n";
        if(nei != from) {
            res *= fpow(fact[child[nei]+1], mod - 2);
            res %= mod;
            dfs(nei, curr);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = fact[1] = 1;

    for(int i=2;i<=200000;i++){
        fact[i] = (fact[i-1] * i) % mod;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        res = 1;
        for(int i = 0; i <= n; ++i) {
            child[i] = 0;
        }
        for(int i=0;i<=n;i++) g[i].clear();

        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        chilrenNumber(1, -1);
        // for(int i = 1; i <= n; ++i) {
        //     cout << child[i] << " ";
        // }
        // cout << "\n";

        dfs(1, -1);

        cout << res << "\n";

    }

 
    return 0;
}
