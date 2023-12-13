#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node1 {
    Node1 *l, *r;
    ll val;

    void pull(ll offset) {
        val = min(l->val, r->val + offset);
    }
};

class SegmentTree1 {
    Node1* root = nullptr;
    int l, r;

    // static
    Node1* _build(int left, int right, vector<int>& vals) {
        Node1* curr = new Node1();
        if(left == right) {
            curr->l = curr->r = nullptr;
            curr->val = vals[left];
            return curr;
        } 

        int mid = left + (right - left) / 2;
        Node1* l = _build(left, mid, vals);
        Node1* r = _build(mid + 1, right, vals);

        curr->l = l;
        curr->r = r;

        curr->pull(mid + 1 - left);
        return curr;
    }

    void _modify(Node1* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->val = val;
            return;
        }
    
        int mid = l + (r - l) / 2;
        
        // TODO
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull(mid + 1 - l);
    }

    ll _query(Node1* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return INT_MAX; // TODO
        if(l >= ql && r <= qr) return curr->val;
        
        int mid = l + (r - l) / 2;
        ll left = _query(curr->l, l, mid, ql, qr);
        if(left == INT_MAX) {
            return _query(curr->r, mid + 1, r, ql, qr);
        } else {
            return min(left, _query(curr->r, mid + 1, r, ql, qr) + mid + 1 - ql);
        }
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
        return _query(root, l, r, ql, qr);
    }
};

struct Node2 {
    Node2 *l, *r;
    ll val;

    void pull(ll offset) {
        val = min(l->val + offset, r->val);
    }
};

class SegmentTree2 {
    Node2* root = nullptr;
    int l, r;

    // static
    Node2* _build(int left, int right, vector<int>& vals) {
        Node2* curr = new Node2();
        if(left == right) {
            curr->l = curr->r = nullptr;
            curr->val = vals[left];
            return curr;
        } 

        int mid = left + (right - left) / 2;
        Node2* l = _build(left, mid, vals);
        Node2* r = _build(mid + 1, right, vals);

        curr->l = l;
        curr->r = r;

        curr->pull(right - mid);
        return curr;
    }

    void _modify(Node2* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->val = val;
            return;
        }
    
        int mid = l + (r - l) / 2;
        
        // TODO
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull(r - mid);
    }

    ll _query(Node2* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return INT_MAX; // TODO
        if(l >= ql && r <= qr) return curr->val;
        
        int mid = l + (r - l) / 2;
        ll right = _query(curr->r, mid + 1, r, ql, qr);
        if(right == INT_MAX) {
            return _query(curr->l, l, mid, ql, qr);
        } else {
            return min(_query(curr->l, l, mid, ql, qr) + (qr - mid), right);
        }
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
        return _query(root, l, r, ql, qr);
    }
};

int main() { _
    int n, q;
    cin >> n >> q;

    vector<int> vals(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }

    SegmentTree1 st1;
    st1.build(1, n, vals);

    SegmentTree2 st2;
    st2.build(1, n, vals);

    int a, b, c;
    while(q--) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            st1.modify(b, b, c);
            st2.modify(b, b, c);
            vals[b] = c;
        } else {
            cin >> b;
            // cout << st1.query(b + 1, n) + 1 << " " << st2.query(1, b - 1) + 1 << " " << vals[b] << "\n";
            cout << min(min(st1.query(b + 1, n), st2.query(1, b - 1)) + 1, (ll) vals[b]) << "\n";
        }
    }
    return 0;
}