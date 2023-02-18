#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define te cout << "t\n";

using namespace std;

int binarySearch(vector<int>& mono, int len, int num, vector<int>& arr) {
    int l = 0, r = len - 1, m;
    while(r - l > 1) {
        m = (r + l) / 2;
        if(arr[mono[m]] < num) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

void show(vector<int>& from, int index, vector<int>& arr, int len) {
    if(index < 0 || index >= len) return;
    show(from, from[index], arr, len);
    cout << arr[index] << "\n";
}

vector<int> arr(100);
int main() { _
    int ttt;
    arr.clear();
    while(cin >> ttt) {
        arr.push_back(ttt);
    };

    int n = arr.size();
    int len = 1;
    vector<int> mono(n, 0);
    vector<int> from(n, -1);

    mono[0] = 0;
    for(int i = 1; i < n; ++i) {
        if(arr[i] > arr[mono[len - 1]]) {
            mono[len] = i;
            from[i] = mono[len - 1];
            len++;

        } else if(arr[i] < arr[mono[0]]) {
            mono[0] = i;
            from[i] = -1;
        } else if(arr[i] < arr[mono[len - 1]]){
            int temp = binarySearch(mono, len, arr[i], arr);
            mono[temp] = i;
            from[i] = temp > 0 ? mono[temp - 1] : -1;
        }
    }
    cout << len << "\n-\n";

    show(from, mono[len - 1], arr, n);

    return 0;
}