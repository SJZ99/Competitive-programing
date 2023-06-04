#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define N (int) 1e5

using namespace std;

bitset<N + 1> isPrime;
vector<int> primes;

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

bool is_prime(int x) {
    if(x == 1) return false;
    if(x < N) return isPrime[x];
    else {
        for(int i : primes) {
            if(x % i == 0) {
                // cout << i << " ";
                return false;
            }
        }
        return true;
    }
}

int main() { 
    primes.clear();
    primes.reserve(N / 16);
    isPrime.flip();

    eulur();

    int q;
    cin >> q;

    int x;
    while(q--) {
        cin >> x;
        if(is_prime(x)) {
            cout << "P\n";
        } else {
            cout << "NP\n";
        }
    }

    return 0;
}