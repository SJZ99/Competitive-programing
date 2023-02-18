#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define d puts("d");

using namespace std;
// i r
int sol[9];
int cnt = 1;

void show() {
    cout << setw(2) << cnt++ << "      ";
    for(int i = 1; i <= 8; ++i) {
        cout << sol[i];
        if(i != 8) {
            cout << " ";
        }
    }
    cout << "\n";
}

bool isLegal(int r, int c) {
    // cout << r << " " << c << "\n";
    if(r < 0 || r > 8 || c < 0 || c > 8) return false;
    
    for(int i = 1; i <= 8; ++i) {
        if(sol[i] == 0) continue;

        if((r == sol[i] && c != i)
        || (abs(c - i) == abs(sol[i] - r) && c - i != 0) 
        || (c == i && sol[i] != r && sol[i] != 0)) {
            return false;
        }
    }
    
    return true;
}

void dfs(int r, int c) {

    sol[c] = r;
    // cout << r << " " << c << "\n";
    if(sol[8] != 0 && c >= 7) {
        show();
        return;
    }

    for(int i = 1; i <= 8; ++i) {
        if(isLegal(i, c + 1)) {
            int tr = sol[c + 1];
            dfs(i, c + 1);
            sol[c + 1] = tr;
        }
    }

}

int main() { _
    int t;
    cin >> t;
    while(t--) {
        int r, c; 
        cin >> r >> c;
        cnt = 1;

        cout << ("SOLN       COLUMN\n");
        cout << (" #      1 2 3 4 5 6 7 8\n\n");

        for(int i = 1; i <= 8; ++i) {
            memset(sol, 0, sizeof(int) * 9);
            sol[c] = r;
            if(isLegal(i, 1)) {
                dfs(i, 1);
            }
        }
        if(t > 0) cout << "\n";
    }

    return 0;
}