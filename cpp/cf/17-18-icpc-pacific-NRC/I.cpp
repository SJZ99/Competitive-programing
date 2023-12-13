#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#include <ext/rope>

#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using namespace __gnu_cxx;
using ll = long long int;

void read(vector<pair<ll, int>>& op, set<ll>& dis) {
    ll p;
    char c;
    while(true) {
        cin >> c;
        cin.ignore();
        if(c == 'E') {
            break;
        }

        cin >> p;
        p--;
        cin.ignore();
        
        dis.insert(p);
        dis.insert(p + 1);
        dis.insert(p - 1);

        if(c == 'D') {
            op.push_back({p, -1});
            
        } else if(c == 'I') {
            cin >> c;
            cin.ignore();
            op.push_back({p, (int)c});
        }
    }
}

int main() { _
    // index, operand
    vector<pair<ll, int>> op1;
    vector<pair<ll, int>> op2;
    set<ll> dis;

    read(op1, dis);
    read(op2, dis);

    vector<int> vec(dis.begin(), dis.end());
    for(int i = 0; i < op1.size(); ++i) {
        op1[i].first = lower_bound(vec.begin(), vec.end(), op1[i].first) - vec.begin();
    }

    for(int i = 0; i < op2.size(); ++i) {
        op2[i].first = lower_bound(vec.begin(), vec.end(), op2[i].first) - vec.begin();
    }
    
    rope<int> rp1;
    rope<int> rp2;
    
    int size = dis.size() + 1;
    for(int i = -1; i <= size; ++i) {
        rp1 += i;
    }

    for(int i = -1; i <= size; ++i) {
        rp2 += i;
    }

    int index;
    // executing operations
    for(int i = 0; i < op1.size(); ++i) {
        index = op1[i].first;
        if(op1[i].second == -1) {
            rp1.erase(index, 1);
        } else {
            rp1.insert(index, op1[i].second);
        }
    }

    for(int i = 0; i < op2.size(); ++i) {
        index = op2[i].first;
        if(op2[i].second == -1) {
            rp2.erase(index, 1);
        } else {
            rp2.insert(index, op2[i].second);
        }
    }

    for(int i : rp1) {
        cout << i << " ";
    } cout << "\n";

    for(int i : rp2) {
        cout << i << " ";
    } cout << "\n";

    if(rp1 == rp2) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }

    return 0;
}