#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n;
    vector<int> v(200, 0);

    cin >> n;
    cin.ignore();
    cin.ignore();

    while(n--) {
        int len = 0;
        v.clear();

        while(1) {
            string s = "";
            getline(cin, s);
            if(s.empty()) {
                break;
            }
            v.push_back(strtol(s.c_str(), NULL, 10));
            len++;
        }

        int dp[len][2] = {0};
        dp[0][0] = 1;
        dp[0][1] = 0;

        int front[len] = {0};
        for(int i = 1; i < len; ++i) {
            int temp = 0, currJ = -1;
            front[i] = i;
            for(int j = i - 1; j >= 0; --j) {
                if(v[j] < v[i] && dp[j][0] > temp) {
                    temp = max(dp[j][0], temp);
                    currJ = j;
                    front[i] = j;
                }
            }
            dp[i][0] = temp + 1;

            currJ = dp[i - 1][0] > dp[i - 1][1] ? 0 : 1;
            dp[i][1] = dp[i - 1][currJ];
        }

        int m = dp[len - 1][0]> dp[len - 1][1] ? 0 : 1;
        cout << "Max hits: " << dp[len - 1][m] << "\n";

        int last = 0;
        for(int i = 0; i < len; ++i) {
            if(dp[i][0] == dp[len - 1][m]) {
                last = i;
            }
        }

        int index = last;
        int res[len] = {0};
        int cnt = 0;
        while(front[index] != index) {
            res[cnt] = index;
            index = front[index];
            cnt++;
        }

        res[cnt] = index;
        for(int i = cnt; i >= 0; --i) {
            cout << v[res[i]] << "\n";
        }
        

        if(n) cout << "\n";
    }


    return 0;
}