#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n;
    cin >> n;
    char input[20] = "";
    int in  = 0;
    int len = 0;
    int set[10] = {0};

    for(int i = 0; i < n; ++i) {
        cin >> input;
        len = strlen(input);
        in = atoi(input + len - 1);
        set[in]++;
    }

    for(int i = 0; i < 10; ++i) {
        set[i]--;
        for(int j = 0; j < 10; ++j) {
            set[j]--;
            for(int k = 0; k < 10; ++k) {
                set[k]--;
                if(set[i] >= 0 && set[j] >= 0 && set[k] >= 0) {
                    if((i + j + k) % 10 == 0) {
                        cout << "YES\n";
                        return 0;
                    }
                }
                set[k]++;
            }
            set[j]++;
        }
        set[i]++;
    }
    cout << "NO\n";
    return 0;
}