#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef vector<vector<int>> matrix;

void clip(matrix& m, int r, int c) {
    int temp = 0;
    for(int i = 0; i < c; ++i) {
        for(int j = 0; j < r / 2; ++j) {
            temp = m[j][i];
            m[j][i] = m[r - j - 1][i];
            m[r - j - 1][i] = temp;
        }
    }
}

void rotate(matrix& m, int r, int c) {
    matrix another = vector<vector<int>>(c, vector<int>(r, 0));

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            another[c - 1 - j][i] = m[i][j];
        }
    }

    m = another;
}

int main() { _
    
    int r, c, m;
    vector<int> operation(15, 0);
    while(cin >> r >> c >> m) {
        operation.clear();
        matrix ma = vector<vector<int>>(max(r, c), vector<int>(max(r, c), 0));
        matrix& mb = ma;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> ma[i][j];
            }
        }
        
        for(int i = 0; i < m; ++i) {
            cin >> operation[i];
        }

        int temp;
        for(int i = m - 1; i >= 0; --i) {
            if(operation[i]) {
                clip(ma, r, c);
            } else {
                rotate(ma, r, c);
                temp = r;
                r = c; 
                c = temp;
            }
        }

        cout << r << " " << c << "\n";
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cout << ma[i][j];
                if(j != c - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}