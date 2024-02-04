#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef vector<vector<int>> matrix;

void readInput(stringstream& ss, string line, vector<int>& arr) {
    ss.str("");
    ss.clear();
    ss << line;
    arr.clear();

    int element;
    int length = 0;

    while(!ss.eof()) {
        ss >> element;
        arr.push_back(element);
        // cout << element << " ";
    }
    length = arr.size();
}

bool dp(vector<int>& v) {
    int length = v.size();
    if(length <= 1) {
        return false;
    }
    int sum = 0;
    for(int i = 0; i < length; ++i) {
        sum += v[i];
    }
    matrix m = vector<vector<int>>(length + 1, vector<int>(sum + 1, 0));

    // cout << "\n" << v[0] << "\n";

    m[1][v[0]] = 1;
    for(int i = 2; i <= length; ++i) {
        for(int j = 1; j <= sum; ++j) {
            m[i][j] = m[i - 1][j] || ((j - v[i - 1]) > 0 ? m[i - 1][j - v[i - 1]] : 0);
            // cout << m[i][j] << " ";
            if(i == length && j * 2 == sum) {
                // cout << "\n" << i << " " << j << "\n";
                return m[i][j];
            }
        }
        // cout << "\n";
    }

    return 0;
}

int main() {
    fastio

    int t;
    cin >> t;
    stringstream ss;
    string temp;
    vector<int> v;

    cin.ignore();
    while(t--) {
        getline(cin, temp);
        readInput(ss, temp, v);

        if(dp(v)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}