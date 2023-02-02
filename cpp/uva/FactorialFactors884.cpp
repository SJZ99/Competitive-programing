#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N 1000000
using namespace std;

int main() { _
    vector<int> primes;
    int factors[N + 1] = {0};
    bitset<N + 1> isPrime;
    isPrime.flip();
    // memset(isPrime, 1, (N + 1) * sizeof(bool));

    for(int i = 2; i <= N; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            factors[i] = 1;
        }

        for(int prime : primes) {
            isPrime[i * prime] = false;
            factors[i * prime] = factors[i] + 1;

            if(i % prime == 0) break;
        }

    }

    int tar;
    while(cin >> tar) {
        cout << factors[tar] << "\n";
    }

    return 0;
}