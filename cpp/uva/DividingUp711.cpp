#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
bool dp[100][60000];

int main() { _
    int arr[6] = {0};
    vector<int> w;
    int total = 0;
    int collection = 1;
    while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5]) {
        memset(dp, 0, 6000000 * sizeof(bool));
        bool allZero = true;
        total = 0;
        for(int i = 0; i < 6; ++i) {
            total += arr[i] * (i + 1);
            if(arr[i] != 0) {
                allZero = false;
            }
        }

        if(allZero) break;

        if((total / 2) * 2 != total) {
            cout << "Collection #" << collection << ":\n";
            cout << "Can't be divided.\n\n";
            collection++;
            continue;
        }

        w.clear();
        for(int i = 0; i < 6; ++i) {
            int j = 1;
            while(arr[i] > 0) {
                if(arr[i] >= j) {
                    w.push_back(j * (i + 1));
                    arr[i] -= j;
                    j *= 2;
                } else {
                    w.push_back(arr[i] * (i + 1));
                    arr[i] = 0;
                }
            }
        }

        bool isSuccess = false;
        int target = total / 2 + 5;

        dp[0][0] = true;
        dp[0][w[0]] = true;
        if(dp[0][total / 2]) {
            isSuccess = true;
        }
        for(int i = 1; i < w.size(); ++i) {

            for(int j = 1; j < target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if(j >= w[i]) {
                    dp[i][j] |= dp[i - 1][j - w[i]];
                }

            }

            if(dp[i][total / 2] || isSuccess) {
                // cout << i << " " << total / 2 << "\n";
                isSuccess = true;
                break;
            }
        }

        cout << "Collection #" << collection << ":\n";
        if(isSuccess) {
            cout << "Can be divided.\n\n";
        } else {
            cout << "Can't be divided.\n\n";
        }

        collection++;
    }

    return 0;
}