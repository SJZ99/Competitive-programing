#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node {
    Node *l, *r;
    ll val;
    ll tag;

    void pull() {
        val = min(l->val, r->val);
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
            curr->val = vals[left];
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

    ll _query(Node* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return INT_MAX; // TODO
        if(l >= ql && r <= qr) return curr->val;
        
        int mid = l + (r - l) / 2;
        
        // TODO
        return min(_query(curr->l, l, mid, ql, qr), _query(curr->r, mid + 1, r, ql, qr));
    }

public: 
    void build(int left, int right, vector<int>& vals) {
        l = left, r = right;
        
        // static or dynamic
        root = _build(left, right, vals);
    }

    ll query(int ql, int qr) {
        return _query(root, l, r, ql, qr);
    }
};

int main() { _
    int n, m;
    cin >> n >> m;

    vector<int> vals(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }

    SegmentTree st;
    st.build(1, n, vals);

    int a, b;
    while(m--) {
        cin >> a >> b;
        cout << st.query(a, b) << "\n";
    }
    return 0;
}