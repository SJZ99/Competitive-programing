#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define N ((int) 1e6 + 1)

bitset<N + 1> isPrime;
vector<int> primes;

void init() {
    primes.clear();
    primes.reserve((int) 1e5);
    isPrime.flip();
}

void eulur() {
    for(int i = 2; i < N; ++i) {
        if(isPrime[i]) primes.push_back(i);
        
        for(int j : primes) {
            if(N / i < j) break;

            isPrime[i * j] = 0;
            if(i % j == 0) {
                break;
            }
        }
    }
}

int main() { _
    int x;
    cin >> x;

    init();
    eulur();

    int cnt = 0;
    int top = primes.size() - 1;
    
    while(primes[top] >= x) top--;

    while(x >= 4) {
        // cout << x << endl;

        int t = top;
        int b = 0;

        ll sum = primes[t] + primes[b];
        while(sum != x) {
            if(sum > x) {
                t--;
            } else {
                b++;
            }
            sum = primes[t] + primes[b];
        }

        x = primes[t] - primes[b];

        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}