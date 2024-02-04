#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<int> A(20), B(20), C(20);
int curr = 0;

void out() {
    cout << "A=>";
    for(int i = 0; i < A.size(); ++i) {
        if(i == 0) cout << "   ";
        cout << A[i];
        if(i < A.size() - 1) cout << " ";
    }
    cout << "\n";
    cout << "B=>";
    for(int i = 0; i < B.size(); ++i) {
        if(i == 0) cout << "   ";
        cout << B[i];
        if(i < B.size() - 1) cout << " ";
    }
    cout << "\n";
    cout << "C=>";
    for(int i = 0; i < C.size(); ++i) {
        if(i == 0) cout << "   ";
        cout << C[i];
        if(i < C.size() - 1) cout << " ";
    }
    cout << "\n\n";
}

void honoi(int n, int t, vector<int>& a, vector<int>& b, vector<int>& c) {

    if(n == 1) {
        c.push_back(a.back());
        a.pop_back();
        if(curr <= t) {
            out();
            curr++;
        } else return;
    } else {
        honoi(n - 1, t, a, c, b);

        c.push_back(a.back());
        a.pop_back();
        if(curr <= t) {
            out();
            curr++;
        } else return;

        honoi(n - 1, t, b, a, c);
    }
}

int main() { _
    int n, t;
    int cnt = 1;
    while(cin >> n >> t && (n != 0 || t != 0)) {
        cout << "Problem #" << cnt << "\n\n";
        A.resize(0), B.resize(0), C.resize(0);
        curr = 1;
        for(int i = n; i >= 1; --i) {
            A.push_back(i);
        }
        out();
        honoi(n, t, A, B, C);
        cnt++;
    }

    return 0;
}