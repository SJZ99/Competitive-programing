#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef pair<int, int> Point;

int step = 0;
bool move(vector<vector<int>> m, int x, int y) {

}

int main() { _
    
    vector<vector<int>> m(6, vector<int>(6, 0));

    bool atRow2 = false;
    bool con = true;
    vector<int> obstacle;
    int last = -1;
    int length = 0;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            cin >> m[i][j];

            if(i == 2 && m[i][j] == 1)  {
                atRow2 = true;
                length++;
            }
            if(i == 2 && con && atRow2 && m[i][j] != 1) {
                con = false;
                last = j - 1;
            }
            if(i == 2 && atRow2 && m[i][j] != 1 && m[i][j] != 0) {
                obstacle.push_back(j);
            }
        }
    }

    if(!atRow2) {
        cout << "-1\n";
        return 0;
    }

    step = 6 - (last - length + 1);
    if(obstacle.size() <= 0) {
        cout << step << "\n";
        return 0;
    }


    return 0;
}