#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef pair<int, int> pii;

int factorize(int x) {
    if(x == 1) {
        return -1;
    }
    long long int sum = 1;

    for(int i = 2; i <= sqrt(x); ++i) {
        if(x % i == 0) {
            sum += i;
            if(i != x / i)
                sum += (x / i);
        }

        if(sum > x) {
            return 1;
        }
    }

    if(sum > x) {
        return 1;
    } else if(sum == x) {
        return 0;
    } else {
        return -1;
    }
}

int main() { _
    int t;
    cin >> t;

    int n;
    while(t--) {
        cin >> n;
        int res = factorize(n);

        if(res == 1) {
            cout << "abundant\n";
        } else if(res == 0) {
            cout << "perfect\n";
        } else {
            cout << "deficient\n";
        }
    }

    return 0;
}