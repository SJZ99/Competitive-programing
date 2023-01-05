#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define int long long int
using namespace std;
vector<int> v1;
vector<int> v2;
set<int> halfRes1;
set<int> halfRes2;
int n, t;

void dfs1(vector<int>& v, int count, int sum, set<int>& result) {
    if(count == v.size()) {
        if(sum <= t) {
            result.insert(sum);
        }
        return;
    }
    dfs1(v, count + 1, sum, result);
    dfs1(v, count + 1, sum + v[count], result);
}

int binarySearch(vector<int>& v, int value) {
    int l = 0, r = v.size(), m = (r + l) / 2;
    while(r - l > 1) {
        m = (r + l) / 2;
        if(value + v[m] == t) {
            return t;
        } else if(value + v[m] > t) {
            r = m;
        } else {
            l = m;
        }
    }
    return value + v[l];
}

// void dfs2()

signed main() { _
    cin >> n >> t;
    int temp;
    for(int i = 0; i < n / 2; ++i) {
        cin >> temp;
        v1.push_back(temp);
    }

    for(int i = n / 2; i < n; ++i) {
        cin >> temp;
        v2.push_back(temp);
    }

    dfs1(v1, 0, 0, halfRes1);
    dfs1(v2, 0, 0, halfRes2);

    vector<int> half1(halfRes1.size());
    half1.assign(halfRes1.begin(), halfRes1.end());

    // for(int i = 0; i < half1.size(); ++i) {
    //     cout << half1[i] << " ";
    // }    cout << "\n";


    vector<int> half2(halfRes2.size());
    half2.assign(halfRes2.begin(), halfRes2.end());

    // for(int i = 0; i < half2.size(); ++i) {
    //     cout << half2[i] << " ";
    // }    cout << "\n";


    int maxx = INT_MIN;
    for(int i = 0; i < half1.size(); ++i) {
        // cout << binarySearch(half2, half1[i]) << " ";
        maxx = max(binarySearch(half2, half1[i]), maxx);
    }
    // cout << "\n";

    cout << maxx << "\n";
    return 0;
}