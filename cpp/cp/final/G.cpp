#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    int n;
    cin >> n;

    unordered_map<int, int> map;
    for(int i = 0; i < n; ++i) {
        int h, m;
        string p;
        cin >> h >> m >> p;
        int total = m;
        total += h * 60;
        if(p.compare("p.m.")) {
            total += 12 * 60;
        }

        cout << ++map[total] << "\n";
    }
    return 0;
}