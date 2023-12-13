#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
unordered_map<int, int> dif;

int main() { _
    int n;
    cin >> n;


    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        dif[u]--;
        dif[v]++;
    }

    int a = 0, b = 0;
    for(auto p : dif) {
        if(p.second != 0) {
            if(p.second < 0) {
                b = p.first;
            } else if(p.second > 0) {
                a = p.first;
            }
        }
    }

    cout << a << " " << b << "\n";

    return 0;
}