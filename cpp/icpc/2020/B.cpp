#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
unordered_set<int> resSet;
// sign + - * -> 0 1 2
vector<int> expression;
int evaluate() {
    vector<int> ex(expression);
    // for(int i = 0; i < ex.size(); ++i) {
    //     if(i % 2 == 1) {
    //         if(ex[i] == 0) cout << " + ";
    //         else if(ex[i] == 1) cout << " - ";
    //         else cout << " * ";
    //     } else {
    //         cout << ex[i];
    //     }
    // }
    
    for(int i = 0; i < ex.size(); ++i) {
        if(i % 2 == 1 && ex[i] == 2) {
            ex[i - 1] = ex[i - 1] * ex[i + 1];
            ex.erase(ex.begin() + i, ex.begin() + i + 2);
            i -= 2;
        }
    }

    int res = ex[0];
    for(int i = 2; i < ex.size(); i += 2) {
        res += (ex[i - 1] == 0 ? 1 : -1) * ex[i];
    }
    // cout << " = " << res << "\n";
    return res;
}
void dfs(int index, int sign, vector<int>& arr) {
    // cout << arr[index] << " ";
    // cout << index << "\n";
    if(index != 0) {
        expression.push_back(sign);
        expression.push_back(arr[index]);
    } else {
        expression.push_back(arr[index]);
    }

    if(index == arr.size() - 1) {
        int curr = evaluate();
        if(curr >= 0) { 
            resSet.insert(curr);
            // cout << curr << "\n";
        }
        expression.pop_back();
        expression.pop_back();
        return;
    }

    // cout << arr[index];
    for(int i = 0; i < 3; ++i) {
        dfs(index + 1, i, arr);
    }

    if(index == 0) expression.clear();
    else expression.pop_back(), expression.pop_back();
}

int main() { _
    vector<int> v;
    int temp;
    for(int i = 0; i < 4; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    do {
        vector<int> combination;
        // 1 1 1 1
        combination.clear();
        combination.push_back(v[0]);
        combination.push_back(v[1]);
        combination.push_back(v[2]);
        combination.push_back(v[3]);
        dfs(0, 0, combination);

        // 2 2
        combination.clear();
        combination.push_back(v[0] * 10 + v[1]);
        combination.push_back(v[2] * 10 + v[3]);
        dfs(0, 0, combination);

        // 2 1 1
        combination.clear();
        combination.push_back(v[0] * 10 + v[1]);
        combination.push_back(v[2]);
        combination.push_back(v[3]);
        dfs(0, 0, combination);
        
        // 1 2 1
        // combination.clear();
        // combination.push_back(v[0]);
        // combination.push_back(v[1] * 10 + v[2]);
        // combination.push_back(v[3]);
        // dfs(0, 0, combination);

        // 1 1 2
        combination.clear();
        combination.push_back(v[0]);
        combination.push_back(v[1]);
        combination.push_back(v[2] * 10 + v[3]);
        dfs(0, 0, combination);

        // 3 1
        combination.clear();
        combination.push_back(v[0] * 100 + v[1] * 10 + v[2]);
        combination.push_back(v[3]);
        dfs(0, 0, combination);

        // 1 3
        // combination.clear();
        // combination.push_back(v[0]);
        // combination.push_back(v[1] * 100 + v[2] * 10 + v[3]);
        // dfs(0, 0, combination);

    } while(next_permutation(v.begin(), v.end()));

    // for(int i : resSet) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << resSet.size() << "\n";
    return 0;
}