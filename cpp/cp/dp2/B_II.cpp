#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
int dp1[100005];
int dp2[100005];

int main() { _
    string a, b;
    cin >> a >> b;

    int len1 = a.length();
    int len2 = b.length();
    int* dpa = dp1, *dpb = dp2, *temp = NULL;
    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            
            if(a[i - 1] == b[j - 1]) {
                dpb[j] = max(dpb[j], dpa[j - 1] + 1);
            } else {
                dpb[j] = max(dpa[j], dpb[j - 1]);
            }
        }
        temp = dpa;
        dpa = dpb;
        dpb = temp;
        memset(dpb, 0, 100005 * sizeof(int));
    }

    // cout << dp[len1][len2] << "\n";
    if(dpa[len1] * 2 > len1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}