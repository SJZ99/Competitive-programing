#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 1000000
using namespace std;

int factors[N + 1] = {0};
bitset<N + 1> isPrime;
vector<int> primes;

int main() { _
    primes.reserve(78500);
    isPrime.flip();

    for(int i = 2; i <= N; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            factors[i] = 1;
        }

        for(int prime : primes) {
            if(INT_MAX / prime >= i && i * prime > N) break;
            isPrime[i * prime] = 0;
            factors[i * prime] = factors[i] + 1;
            // cout << factors[i * prime] << " ";
            if(i % prime == 0) break;
        }

    }

    for(int i = 2; i <= N; ++i) {
        factors[i] += factors[i - 1];
    }


    int tar = 0;
    while(cin >> tar) {
        cout << factors[tar] << "\n";
    }
    return 0;
}