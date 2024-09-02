#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int ocurr[(int)1e6+1] = {};

int main(void) { _
    int n;
    cin >> n;

    int maxx = INT_MIN;
    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        ocurr[tmp]++;
        maxx = max(maxx, tmp);
    }

    int curr = INT_MIN;
    for(int i = maxx; i >= 1; --i) {
        int divisable = 0;
        for(int j = i; j <= maxx; j += i) {
            divisable += ocurr[j];
        }
        if(divisable > 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
