#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool f(int k,int d, int* p, int n){
    int a = 0;
    int b = p[a] + d;
    int i = 0;
    // cout << d << ": \n";
    while(a < n && b < p[n-1]){
        b = p[a] + d;
        // cout << a << " ";
        while (a < n && p[a] <= b){
            a++;
        }
        i++;
        if (i > k) return false;
    }
    return true;
}

signed main(){
    int n,k;
    cin >> n >> k;
    int p[n];

    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n);
    int left, right, mid;
    left = 0;
    right = (p[n-1] - p[0]);

    while(((right - left) > 1)){
        mid = (left + right) / 2;

        // if(isSpanSuccess(mid, k, p, n)) {
        //     right = mid;
        // } else {
        //     left = mid;
        // }

        if (f(k, mid, p, n)){
            right = mid;
        } else left = mid;
        // cout << "\n";
        // cout << f(k, mid, p, n) << "\n";
        // cout << mid << " ";
    }   

    cout << right << "\n";
}