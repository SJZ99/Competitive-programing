#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

class BIT {
    vector<ll> arr;
    int n;

    int lowbit(int x) {
        return x & -x;
    }

public:
    void build(int n, vector<int> vals) {
        arr = vector<ll>(n + 1, 0);
        this->n = n;
        for(int i = 1; i <= n; ++i) {
            arr[i] += vals[i];
            
            int j = i + lowbit(i);
            if(j <= n) {
                arr[j] += arr[i];
            }
        }
    }

    void modify(int x, bool isIncre) {
        for(int i = x; i <= n; i += lowbit(i)) {
            arr[i] += isIncre ? 1 : -1;
        }
    }

    ll query(int ql, int qr) {
        ll total = 0;
        for(int i = qr; i > 0; i -= lowbit(i)) {
            total += arr[i];
        }
        for(int i = ql - 1; i > 0; i -= lowbit(i)) {
            total -= arr[i];
        }

        return total;
    }
};

int main() { _
    int n, q;
    cin >> n >> q;
    vector<int> vals(n + 1);
    unordered_set<int> p;

    vector<vector<int>> queries(q, vector<int>(3, 0));
    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
        p.insert(vals[i]);
    }

    for(int i = 0; i < q; ++i) {
        char temp;
        cin >> temp >> queries[i][1] >> queries[i][2];
        queries[i][0] = temp == '?';

        if(queries[i][0] == 1) {
            p.insert(queries[i][1]);
            p.insert(queries[i][2]);
        } else {
            p.insert(queries[i][2]);
        }
    }

    vector<int> all(p.begin(), p.end());
    sort(all.begin(), all.end());
    int len = all.size();
    for(int i = 0; i < q; ++i) {
        if(queries[i][0] == 1) {
            queries[i][1] = lower_bound(all.begin(), all.begin() + len, queries[i][1]) - all.begin() + 1;
            queries[i][2] = lower_bound(all.begin(), all.begin() + len, queries[i][2]) - all.begin() + 1;
        } else {
            queries[i][2] = lower_bound(all.begin(), all.begin() + len, queries[i][2]) - all.begin() + 1;
        }
    }

    vector<int> freq(all.size() + 1);
    for(int i = 1; i <= n; ++i) {
        vals[i] = lower_bound(all.begin(), all.begin() + len, vals[i]) - all.begin() + 1;
        freq[vals[i]]++;
    }

    BIT bit;
    bit.build(all.size(), freq);

    for(int i = 0; i < q; ++i) {
        if(queries[i][0] == 0) {
            bit.modify(vals[queries[i][1]], false);
            vals[queries[i][1]] = queries[i][2];
            bit.modify(queries[i][2], true);
        } else {
            cout << bit.query(queries[i][1], queries[i][2]) << "\n";
        }
    }
    return 0;
}