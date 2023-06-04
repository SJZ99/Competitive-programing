#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define N (int) 1e9 + 7
using namespace std;

long long fast_power(long long base, long long deg, int mod){
    long long sum = 1;
    while(deg > 0){
        if(deg & 1){
            sum = sum*base%mod;
        }
        deg >>= 1;
        base = base*base%mod;
    }
    return sum;
}

int main() { _
    int t;
    cin >> t;
    
    int a, b, c;
    while(t--) {
        cin >> a >> b >> c;
        long long int temp = fast_power(b, c, N - 1);
        cout << fast_power(a, temp, N) << "\n";
    }

    return 0;
}