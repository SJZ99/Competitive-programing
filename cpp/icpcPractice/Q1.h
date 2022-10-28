#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define debug(x) cout << x << "\n";
using namespace std;

void solve() {

    int t = 0;
    cin >> t;
    int arr[] = {INT_MIN, INT_MIN, INT_MIN};
    string name, tn;
    char charray[10000] = {0};
    char space;
    int in[3];
    for(int i = 0; i < t; ++i) {
        cin >> in[0] >> in[1] >> in[2];
        cin.getline(charray, sizeof(charray));
        tn = string(charray);
        if(tn[0] = ' ') {
            // cout << tn[0] << tn;
            tn = tn.substr(1);
        }

        for(int i = 0; i < 3; ++i) {
            if(in[i] > arr[i]) {
                arr[0] = in[0];
                arr[1] = in[1];
                arr[2] = in[2];
                name = tn;
            } else if(in[i] < arr[i]) {
                break;
            }
        }
    }

    cout << name << "\n";
}