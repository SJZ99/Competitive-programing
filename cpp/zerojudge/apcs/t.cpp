#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

#define N 10000
class Solution {
    long long int dp[N][N] = {0};
    long long C(long long int n, long long int k) {
        if(k == 1) {
            return n;
        } else if(k == 2) {
            return n * (n - 1) / 2;
        }
        
        if(n < N && k < N && dp[n][k] != 0) {
            return dp[n][k];
        } else if(n < N && k < N){
            dp[n][k] = C(n - 1, k) + C(n - 1, k - 1);
            return dp[n][k];
        } else {
            return C(n - 1, k) + C(n - 1, k - 1);
        }
    }
public:
    long long countGood(vector<int>& nums, int k) {
        memset(dp, 0, sizeof(long long int) * N * N);
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }
        
        long long int t = 0;
        for(auto p : map) {
            if(p.second >= 2) {
                t += C(p.second, 2);
            }
        }
        
        return C(t, k);
        
    }
};