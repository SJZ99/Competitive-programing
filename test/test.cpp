#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int a[100005], d[1<<19]; // d is minimum diff

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n;
    cin >>c>>n;
    memset(d, -1, sizeof(d));
    queue<int> que;
    for(int i=0;i<n;i++){
        string s;
        cin >>s;
        for(int j=0;j<c;j++){
            a[i] = a[i]*2 + (s[j] == 'G');
        }
        int rev = (1 << c) - 1 - a[i];
        d[rev] = 0;
        que.push(rev);
    }
    while(!que.empty()){
        int x = que.front();
        que.pop();
        // cout << x << endl;
        for(int i=0;i<c;i++){
            int rev = x ^ (1 << i); // reverse one bit
            if(d[rev] == -1){
                // cout << rev << endl;
                d[rev] = d[x] + 1;
                que.push(rev);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout <<c - d[a[i]]<<endl;
    }


    return 0;
}