#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

#define N ((int) 2e6 + 5)

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
    return isPrime[x];
}

int main() { _
    primes.clear();
    primes.reserve(N / 5);
    isPrime.flip();

    int n;
    cin >> n;

    eulur();

    // for(int n : primes) {
    //     cout << n << " ";
    // }
    while(n--) {
        int t;
        cin >> t;
        int maxC = 0;
        int p1 = 0;

        int temp;
        bool haveTwo = false;
        for(int i = 0; i < t; ++i) {
            cin >> temp;
            if(is_prime(temp)) {
                p1 = max(p1, temp);
                if(temp == 2) {
                    haveTwo = true;
                }
            } else {
                maxC = max(maxC, temp);
            }
        }

        // cout << maxC << " " << p1 << "\n";
        if(haveTwo && p1 != 2) {
            p1 *= 2;
        }

        if(maxC > p1) {
            cout << "Composite Number!\n";
        } else if(maxC < p1) {
            cout << "Prime Number!\n";
        } else {
            cout << "Tie.\n";
        } 
    }
    return 0;
}