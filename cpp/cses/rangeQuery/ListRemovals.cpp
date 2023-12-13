#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

struct Node {
    Node *l, *r;
    ll val;
    ll count;;

    void pull() {
        count = l->count + r->count;
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
            curr->count = 1;
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

    ll _del(Node* n, int index) {
        n->count--;
        if(n->l != nullptr && n->l->count >= index) {
            return _del(n->l, index);
        } else if(n->r != nullptr) {
            return _del(n->r, index - n->l->count);
        } else {
            return n->val;
        }
    }

public: 
    void build(int left, int right, vector<int>& vals) {
        l = left, r = right;
        
        // static or dynamic
        root = _build(left, right, vals);
    }

    ll del(int index) {
        return _del(root, index);
    }
};

int main() { _
    int n;
    cin >> n;
    vector<int> vals(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }

    SegmentTree st;
    st.build(1, n, vals);

    while(n--) {
        int p;
        cin >> p;
        cout << st.del(p) << " ";
    }

    return 0;
}