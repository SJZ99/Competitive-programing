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

    return n*n - cnt <= k - 1;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int l = 0, r = n*n;

    int ans = 1;

    while(r - l > 1){
        int mid = l + ((r - l) >> 1);
        if(check(mid)) r = mid;
        else l = mid;
    }

    cout << "! " << r << endl;
    cout.flush();

 
    return 0;
}
