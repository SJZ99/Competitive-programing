#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 1000001
using namespace std;

int factors[N] = {0};
int main() { _
    for(int i = 2; i < N; ++i) {
        if(factors[i] != 0) continue;
        for(int j = 1; j < N && i * j < N; ++j) {
            factors[i * j]++;
        }
    }
    
    int num = 0;
    while(cin >> num && num != 0) {
        cout << num << " : " << factors[num] << "\n";
    }
    return 0;
}