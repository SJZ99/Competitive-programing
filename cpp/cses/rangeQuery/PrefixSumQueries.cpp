#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node {
    Node *l, *r;
    ll sum;
    ll maxPrefix;

    void pull() {
        sum = l->sum + r->sum;
        maxPrefix = max(max(l->maxPrefix, l->sum + r->maxPrefix), 0ll);
    }
};

class SegmentTree {
    Node* root = nullptr;
    int l, r;

    // static
    Node* _build(int left, int right, vector<int>& vals) {
        Node* curr = new Node();
        if(left == right) {
            curr->l = curr->r = nullptr;
            curr->sum = vals[left];
            curr->maxPrefix = max(vals[left], 0);
            return curr;
        } 

        int mid = left + (right - left) / 2;
        Node* l = _build(left, mid, vals);
        Node* r = _build(mid + 1, right, vals);

        curr->l = l;
        curr->r = r;

        curr->pull();

        return curr;
    }

    void _modify(Node* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->sum = val;
            curr->maxPrefix = max(0ll, curr->sum);
            return;
        }

        int mid = l + (r - l) / 2;
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull();
    }

    // sum, prefix
    pair<ll, ll> _query(Node* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return {0, INT_MIN};
        if(l >= ql && r <= qr) return {curr->sum, curr->maxPrefix};
        
        int mid = l + (r - l) / 2;
        
        // TODO
        auto q1 = _query(curr->l, l, mid, ql, qr);
        auto q2 = _query(curr->r, mid + 1, r, ql, qr);
        return {q1.first + q2.first, max(max(q1.second, q1.first + q2.second), 0ll)};
    }

public: 
    void build(int left, int right, vector<int>& vals) {
        l = left, r = right;
        
        // static or dynamic
        root = _build(left, right, vals);
    }

    void modify(int ql, int qr, ll val) {
        _modify(root, l, r, ql, qr, val);
    }

    ll query(int ql, int qr) {
        return _query(root, l, r, ql, qr).second;
    }
};

int main() { _
    
    int n, q;
    cin >> n >> q;

    vector<int> vals(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }

    SegmentTree st;
    st.build(1, n, vals);

    int a, b, c;
    while(q--) {
        cin >> a >> b >> c;
        if(a == 1) {
            st.modify(b, b, c);
        } else {
            cout << st.query(b, c) << "\n";
        }
    }
    return 0;
}