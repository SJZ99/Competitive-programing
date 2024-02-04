#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
struct Node {
    Node *l, *r;
    ll val;
    ll tag;

    void pull() {

    }
};

class SegmentTree {
    Node* root = nullptr;
    int l, r;

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

        return curr;
    }

    void _modify(Node* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->tag += val;
            curr->val += val;
            return;
        }

        push(curr, l, r);

        int mid = l + (r - l) / 2;
        _modify(curr->r, mid + 1, r, ql, qr, val);
        _modify(curr->l, l, mid, ql, qr, val);

        curr->pull();
    }

    ll _query(Node* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return -1;
        if(l >= ql && r <= qr) return curr->val;

        push(curr, l, r);

        int mid = l + (r - l) / 2;

        ll left = _query(curr->l, l, mid, ql, qr);
        if(left < 0) {
           return _query(curr->r, mid + 1, r, ql, qr);
        } else {
            return left;
        }
    }

    void push(Node* node, int l, int r) {
        if(l == r) node->tag = 0;
        if(node->tag == 0) return;

        node->l->tag += node->tag;
        node->r->tag += node->tag;
        node->l->val += node->tag;
        node->r->val += node->tag;

        node->tag = 0;
    }
public: 
    void build(int left, int right, vector<int>& vals) {
        l = left, r = right;
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

    vector<int> vals(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    SegmentTree st;
    st.build(0, n - 1, vals);

    int a, b, c;
    while(q--) {
        cin >> a;
        if(a == 1) {
            cin >> a >> b >> c;
            a--, b--;

            st.modify(a, b, c);
        } else if(a == 2) {
            cin >> b;
            b--;
            cout << st.query(b, b) << "\n";
        }
    }
    return 0;
}