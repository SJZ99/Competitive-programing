#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
using namespace std;

int x[20], y[20];
double dist[20][20] = {0};

double dis(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

double match(int state, int finalState, int n) {
    if(state == finalState) {
        return 0;
    }

    double minn = INT_MAX;
    int i = 0;
    for(i = 0; i < 2 * n; ++i) {
        // if find a person who have not been used
        if(!(state & (1 << i))) {
            break;
        }
    }

    for(int j = i + 1; j < 2 * n; ++j) {
        // find another person who have not been used
        if(!(state & (1 << j))) {
            minn = min(minn, dist[i][j] + match((state | (1 << i) | (1 << j)), finalState, n));
        }
    }
    return minn;
}
int main() { _
    int n;
    string ignore;
    int kase = 1;
    while(cin >> n && n != 0) {
        memset(x, 0, sizeof(int) * 20);
        memset(y, 0, sizeof(int) * 20);
        int state = 0;
        int finalState = (1 << (2 * n)) - 1;

        for(int i = 0; i < 2 * n; ++i) {
            cin >> ignore >> x[i] >> y[i];
        }

        for(int i = 0; i < 2 * n; ++i) {
            for(int j = i; j < 2 * n; ++j) {
                dist[i][j] = dist[j][i] = dis(i, j);
            }
        }

        double result = match(state, finalState, n);
        result *= 100;
        result = round(result);
        result /= 100;
        cout << "Case " << kase << ": " << fixed << setprecision(2) << result << "\n";
        kase++;
    }
    return 0;
}

