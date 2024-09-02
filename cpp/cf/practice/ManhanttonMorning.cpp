#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool cmp(pii& a, pii& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pii& a, pii& b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int optimizedLIS(vector<int>& arr) {
    if(arr.size() == 0) {
        return 0;
    }
    
    vector<int> mono;
    mono.push_back(arr[0]);

    for(int i = 1; i < arr.size(); ++i) {
        if(arr[i] >= mono.back()) {
            mono.push_back(arr[i]);
        } else {
            // *lower_bound(mono.begin(), mono.end(), arr[i]) = arr[i];
            *upper_bound(mono.begin(), mono.end(), arr[i]) = arr[i];
        }
    }
    return mono.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> arr;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int xm = 1, ym = 1;
    if(x1 > x2) {
        xm = -1;
        x1 *= -1;
        x2 *= -1;
    }

    if(y1 > y2) {
        ym = -1;
        y1 *= -1;
        y2 *= -1;
    }

    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        a *= xm, b *= ym;
        if(a >= x1 && a <= x2 && b >= y1 && b <= y2) {
            arr.push_back({a, b});
        }
    }

    sort(arr.begin(), arr.end(), cmp);

    
    vector<int> lis(arr.size(), 0);
    // cout << "points\n";
    for(int i = 0; i < arr.size(); ++i) {
        lis[i] = arr[i].second;
        // cout << arr[i].first << " " << arr[i].second << "\n";
    }

    cout << optimizedLIS(lis) << "\n";
    return 0;
}