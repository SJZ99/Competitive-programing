#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
typedef struct {
    int id;
    int weight;
    int iq;
} Elephant;

bool cmp(Elephant a, Elephant b) {
    if(a.weight == b.weight) {
        return a.iq < b.iq;
    } else {
        return a.weight < b.weight;
    }
}

int binarySearch(vector<int>& mono, vector<Elephant> arr, int tar, int n) {
    int l = 0, r = n, m;
    while(r - l > 1) {
        m = (r + l) / 2;
        if(arr[mono[m]].iq > arr[tar].iq) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

void show(vector<int>& from, vector<Elephant>& arr, int index) {
    // cout << index << "\n";
    if(index >= 0 && index < arr.size()) {
        show(from, arr, from[index]);
        // cout << arr[index].id  << " " << arr[index].weight << " " << arr[index].iq << "\n";
        cout << arr[index].id << "\n";
    }
}

int main() { _
    int w, q, n = 1;
    vector<Elephant> arr;

    while(cin >> w >> q) {
        arr.push_back(Elephant { n++, w, q });
    }

    n--;
    sort(arr.begin(), arr.end(), cmp);    

    vector<int> mono(1010, -1);
    vector<int> from(1010, -1);

    int len = 0;
    mono[0] = 0;

    for(int i = 1; i < n; ++i) {
        if(arr[i].iq < arr[mono[len]].iq) {
            mono[len + 1] = i;
            from[i] = mono[len];
            len++;

        } else if(arr[i].iq > arr[mono[0]].iq) {
            mono[0] = i;

        } else if(arr[i].iq > arr[mono[len]].iq) {
            int index = binarySearch(mono, arr, i, len);
            mono[index] = i;
            if(index > 0) {
                from[i] = mono[index - 1];
            }
        }
    }

    cout << len + 1 << "\n";

    show(from, arr, mono[len]);

    return 0;
}