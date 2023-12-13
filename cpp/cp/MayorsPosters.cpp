#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node {
    Node *l = nullptr, *r = nullptr;
    ll tag = 0;
};

class SegmentTree {
    Node* root = nullptr;
    int l, r;
    vector<bool> vis;

    Node* _build(int left, int right) {
        Node* curr = new Node();
        if(left == right) {
            curr->l = curr->r = nullptr;
            curr->tag = 0;
            return curr;
        } 

        int mid = left + (right - left) / 2;
        Node* l = _build(left, mid);
        Node* r = _build(mid + 1, right);

        curr->l = l;
        curr->r = r;

        return curr;
    }

    Node* createNode() {
        Node* n = new Node();
        n->tag = 0;
        return n;
    }
    
    // TODO: dynamic
    void _modify(Node* curr, int l, int r, int ql, int qr, ll val) {
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            curr->tag = val;
            return;
        }

        if(curr->l == nullptr) {
            curr->l = createNode();
        }

        if(curr->r == nullptr) {
            curr->r = createNode();
        }

        push(curr, l, r);

        int mid = l + (r - l) / 2;
        
        // TODO
        if(ql <= mid) {
            _modify(curr->l, l, mid, ql, qr, val);        
        }

        if(qr > mid) {
            _modify(curr->r, mid + 1, r, ql, qr, val);
        }      
    }

    ll _query(Node* curr, int l, int r, int ql, int qr) {
        
        if(r < ql || l > qr) return 0; // TODO
        if(curr->tag != 0) {
            if(!vis[curr->tag]) {
                vis[curr->tag] = true;
                return 1;
            }
            return 0;
        }

        if(l == r) { return 0; }

        int mid = l + (r - l) / 2;
        return _query(curr->l, l, mid, ql, qr) + _query(curr->r, mid + 1, r, ql, qr);
    }

    // only range update need
    void push(Node* node, int l, int r) {
        if(l == r) node->tag = 0;
        if(node->tag == 0) return;

        node->l->tag = node->tag;
        node->r->tag = node->tag;

        node->tag = 0;
    }
public: 
    void build(int left, int right) {
        l = left, r = right;
        vis = vector<bool>(right - left + 2);
        root = createNode();
    }

    void modify(int ql, int qr, ll val) {
        _modify(root, l, r, ql, qr, val);
    }

    ll query(int ql, int qr) {
        return _query(root, l, r, ql, qr);
    }
};
int main() { _
    
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        SegmentTree st;

        vector<ll> l(n);
        vector<ll> r(n);
        vector<ll> all;
        all.reserve(4 * n);

        for(int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            all.push_back(l[i]);
            all.push_back(r[i]);
            all.push_back(l[i] + 1);
            all.push_back(r[i] + 1);
        }

        sort(all.begin(), all.end());
        int len = unique(all.begin(), all.end()) - all.begin();

        for(int i = 0; i < n; ++i) {
            l[i] = lower_bound(all.begin(), all.begin() + len, l[i]) - all.begin() + 1;
            r[i] = lower_bound(all.begin(), all.begin() + len, r[i]) - all.begin() + 1;
        }
        st.build(1, len);

        // cout << l[0] << " " << r[0] << "\n";
        for(int i = 0; i < n; ++i) {
            st.modify(l[i], r[i], i + 1);
        }

        cout << st.query(1, len) << "\n";
    }
    return 0;
}