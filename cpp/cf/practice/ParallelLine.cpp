#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;
using pii = pair<ll, ll>;
using pdd = pair<double, double>;

const double eps = 1e-9;

unordered_map<ll, vector<int>> record;

bool check(int a, int b, vector<pii>& arr, int k) {
    ll x1 = arr[a].first, x2 = arr[b].first, y1 = arr[a].second, y2 = arr[b].second;
    ll dx = x2 - x1, dy = y2 - y1;

    record.clear();
    for(int i = 0; i < arr.size(); ++i) {
        ll area = dx * (arr[i].second - y1) - dy * (arr[i].first - x1);
        record[area].push_back(i);
    }

    if(record.size() != k) {
        return false;
    }

    for(auto p : record) {
        if(p.second.size() < 2) {
            return false;
        }
    }

    return true;
}

int main(void) { _
    int n, k;
    cin >> n >> k;

    vector<pii> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    while(true) {
        int idx2 = rand() % n;

        if(0 == idx2) {
            idx2 = (idx2+1) % n;
        }

        if(check(0, idx2, arr, k)) {
            for(auto p : record) {
                cout << p.second.size() << " ";
                for(int idx : p.second) {
                    cout << idx+1 << " ";
                }
                cout << "\n";
            }
            break;
        }
    }

    return 0;
}