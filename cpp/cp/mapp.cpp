#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() { _
    map<pair<int, int>, string> m;
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; ++i) {
        string s;
        int x, y;
        string text;
        cin >> s;
        if(strcmp(s.c_str(), "sudo") == 0) {
            cin >> x >> y >> text;
            m[{x, y}] = text;
        } else {
            sscanf(s.c_str(), "%d", &x);
            cin >> y >> text;
            if(m.find({x, y}) == m.end()) {
                m[{x, y}] = text;
            }
        }
        // cout << x << " " << y << " " << text << "\n";
    } 

    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if(m.find({x, y}) == m.end()) {
            cout << "RUN ERROR\n";
        } else {
            cout << m[{x, y}] << "\n";
        }
    }

    cout << (*m.begin()).second << "\n";
    cout << (*m.rbegin()).second << "\n";

    int maxx = 0;
    string s = "";
    // cout << "\n";
    for(auto p : m) {
        // cout << p.second << "\n";
        if(p.second.size() > maxx) {
            s = p.second;
            maxx = p.second.size();
        }
    }
    cout << s << "\n";
    return 0;
}