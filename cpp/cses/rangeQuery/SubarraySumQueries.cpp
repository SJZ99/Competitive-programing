#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node {
    Node *l, *r;
    ll pre, post, sum, subSum;

    void init(ll val) {
        pre = post = sum = subSum = val;
        pre = max(0ll, pre);
        post = max(0ll, post);
        subSum = max(0ll, subSum);
    }

    void pull() {
        pre = max(l->pre, l->sum + max(r->pre, 0ll));
        post = max(r->post, r->sum + max(l->post, 0ll));
        pre = max(0ll, pre);
        post = max(0ll, post);

        sum = l->sum + r->sum;

        subSum = max(pre, post);
        subSum = max(subSum, l->subSum);
        subSum = max(subSum, r->subSum);
        subSum = max(subSum, l->post + r->pre);
        subSum = max(0ll, subSum);
        // cout << l->subSum << " " << r->subSum << "\n";
        // cout << "SubSum: " << subSum << "\n";
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
            curr->init(vals[left]);
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
            curr->init(val);
            return;
        }

        int mid = l + (r - l) / 2;
        
        // TODO
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull();
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

    ll query() {
        return root->subSum;
    }
};

int main() { _
    int n, q;
    cin >> n >> q;
    
    vector<int> vals(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> vals[i + 1];
    }

    SegmentTree st;
    st.build(1, n, vals);

    int p, v;
    while(q--) {
        cin >> p >> v;
        st.modify(p, p, v);
        cout << st.query() << "\n";
    }
    return 0;
}