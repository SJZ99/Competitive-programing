#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define de cout << "t\n";

using namespace std;

vector<int> mono((int)1e5 + 5);
int main() { 

    int n;
    cin >> n;
    unordered_map<string, int> map;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        map.insert({s, i});
    }

    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(map.find(s) != map.end()) {
            arr.push_back(map[s]);
        }
    }

    // for(int ab : arr) {
    //     cout << ab << " ";
    // }

    // optimal LIS onto arr
    mono.clear();
    mono.push_back(arr[0]);
    int len = 0;
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] > mono[len]) {
            mono.push_back(arr[i]);
            len++;
        } else if (arr[i] < mono[0]) {
            mono[0] = arr[i];
        } else if(arr[i] < mono[len]) {
            *lower_bound(mono.begin(), mono.end(), arr[i]) = arr[i];
        }
    }

    cout << n - mono.size() << "\n";
    return 0;
}