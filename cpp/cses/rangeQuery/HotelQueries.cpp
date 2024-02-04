#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
typedef pair<int, int> pii;

struct Node {
    Node *l, *r;
    ll val;

    void pull() {
        val = max(l->val, r->val);
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

    void _modify(Node* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->val -= val;
            return;
        }

        int mid = l + (r - l) / 2;
        
        // TODO
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull();
    }

    ll _query(Node* curr, int l, int r, int val) {
        
        if(l == r && curr->val >= val) return l;
        else if(l == r) return 0;
        
        int mid = l + (r - l) / 2;
        
        int index = 0;
        if(curr->l->val >= val) {
            index = _query(curr->l, l, mid, val);
        }
        if(index == 0 && curr->r->val >= val) {
            index = _query(curr->r, mid + 1, r, val);
        }

        return index;
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

    ll query(int val) {
        return _query(root, l, r, val);
    }
};

int main() { _
    int n, m;
    cin >> n >> m;

    vector<int> vals(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }

    SegmentTree st;
    st.build(1, n, vals);

    int tar;
    while(m--) {
        cin >> tar;
        int index = st.query(tar);
        if(index != 0) {
            st.modify(index, index, tar);
        }

        cout << index << " ";
    }

    return 0;
}