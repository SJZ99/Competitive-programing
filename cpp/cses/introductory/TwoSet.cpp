#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() { 
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if(sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    ll tar = sum / 2;
    vector<ll> arr;
    arr.reserve(n / 2);

    ll curr = 0;
    ll i = 1, j = n;
    while(curr < tar) {
        arr.push_back(j);
        arr.push_back(i);
        curr += i++ + j--;
        if(curr > tar) {
            curr -= (i - 1);
            --i;
            arr.pop_back();
            break;
        }
    }

    cout << "YES\n";
    cout << arr.size() << "\n";
    sort(arr.begin(), arr.end());
    for(int k = 0; k < arr.size(); ++k) {
        cout << arr[k] << " ";
    }
    cout << "\n" << j - i + 1 << "\n";
    for(int k = i; k <= j; ++k) {
        cout << k << " ";
    }
  
    return 0;
}