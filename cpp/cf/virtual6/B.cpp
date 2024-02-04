#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    string line1, line2;
    cin >> line1 >> line2;

    int n = line1.size();

    int up = 0, down = 0, both = 0;
    for(int i = 0; i < n; ++i) {
        if(line1[i] == '#' && line2[i] == '#') {
            both++;
        } else if(line1[i] == '#') {
            up++;
        } else if(line2[i] == '#') {
            down++;
        }
    }

    // cout << both << " " << up << " " << down << "\n";

    if(up != 0 && down == 0 && both == 0) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            if(i < up) {
                cout << "#";
            } else cout << ".";
        }
        cout << "\n";
        for(int i = 0; i < n; ++i) {
            cout << ".";
        }
    } else if(down != 0 && up == 0 && both == 0) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            cout << ".";
        }
        cout << "\n";
        for(int i = 0; i < n; ++i) {
            if(i < down) {
                cout << "#";
            } else cout << ".";
        }
    } else if(both != 0) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            if(i < up + both) {
                cout << "#";
            } else cout << ".";
        }
        cout << "\n";
        for(int i = 0; i < n; ++i) {
            if(i < up) {
                cout << ".";
            } else if(i < up + both + down) cout << "#";
            else cout << ".";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}