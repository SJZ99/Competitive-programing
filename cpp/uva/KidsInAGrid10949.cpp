#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
#define de cout << "t\n";

using namespace std;

void createGrid(int r, vector<string>& grid) {
    string temp;
    for(int i = 0; i < r; ++i) {
        cin >> temp;
        grid.push_back(temp);
    }
}

vector<int> mono(400000010);
int main() { 
    int tc, cnt = 1;
    cin >> tc;

    while(tc--) {
        int r, c;
        cin >> r >> c;

        // grid
        vector<string> grid;
        createGrid(r, grid);

        string s1 = "", s2 = "";
        string directions;
        int t, x, y;

        // s1
        cin >> t >> x >> y;
        if(t > 0) {
            cin >> directions;
        }

        unordered_map<char, vector<int>> at;
        x--, y--;

        s1.push_back(grid[x][y]);
        at[grid[x][y]] = vector<int>();
        at[grid[x][y]].push_back(0);
        for(int i = 0; i < directions.size(); ++i) {
            if(directions[i] == 'N') {
                x -= 1;
            } else if(directions[i] == 'S') {
                x += 1;
            } else if(directions[i] == 'W') {
                y -= 1;
            } else if(directions[i] == 'E') {
                y += 1;
            }
            s1.push_back(grid[x][y]);

            if(at.find(grid[x][y]) == at.end()) {
                at[grid[x][y]] = vector<int>();
            }
            at[grid[x][y]].insert(at[grid[x][y]].begin(), i + 1);
        }
        
        // s2 and LIS
        vector<int> arr;
        cin >> t >> x >> y;
        if(t > 0) {
            cin >> directions;
        }
        x--, y--;

        s2.push_back(grid[x][y]);
        if(at.find(grid[x][y]) != at.end()) {
            arr.insert(arr.end(), at[grid[x][y]].begin(), at[grid[x][y]].end());
        }

        for(int i = 0; i < directions.size(); ++i) {
            if(directions[i] == 'N') {
                x -= 1;
            } else if(directions[i] == 'S') {
                x += 1;
            } else if(directions[i] == 'W') {
                y -= 1;
            } else if(directions[i] == 'E') {
                y += 1;
            }

            s2.push_back(grid[x][y]);
            
            if(at.find(grid[x][y]) != at.end()) {
                sort(at[grid[x][y]].begin(), at[grid[x][y]].end(), greater<int>());
                arr.insert(arr.end(), at[grid[x][y]].begin(), at[grid[x][y]].end());
            }
        }

        if(s1.size() <= 0) {
            cout << "Case " << cnt << ": " << 0 << " " << s2.size() << "\n";
            cnt++;
            continue;
        } else if(s2.size() <= 0) {
            cout << "Case " << cnt << ": " << s1.size() << " " << 0 << "\n";
            cnt++;
            continue;
        }

        // optimal LIS onto arr
        mono.clear();
        if(arr.size() <= 0) {
            cout << "Case " << cnt << ": " << s1.size() << " " << s2.size() << "\n";
            cnt++;
            continue;
        }
        mono.push_back(arr[0]);
        int len = 0;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] > mono[len]) {
                mono.push_back(arr[i]);
                len++;
            } else if (arr[i] < mono[0]) {
                mono[0] = arr[i];
            } else if(arr[i] < mono[len]) {
                *lower_bound(mono.begin(), mono.end(), arr[i]) = arr[i];
            }
        }
        
        cout << "Case " << cnt << ": " << s1.size() - len - 1 << " " << s2.size() - len - 1 << "\n";
        cnt++;
    }

    return 0;
}