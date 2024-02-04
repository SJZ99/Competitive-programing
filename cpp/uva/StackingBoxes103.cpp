#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

typedef struct {
    int id;
    vector<int> v;
} Box;

// is a bigger than b?
bool isBigger(Box& a, Box b) {
    for(int i = 0; i < a.v.size(); ++i) {
        if(b.v[i] >= a.v[i]) return false;
    }
    return true;
}

bool cmp(Box a, Box b) {
    for(int i = 0; i < a.v.size(); ++i) {
        if(a.v[i] != b.v[i]) {
            return a.v[i] < b.v[i];
        }
    }
}

void show(vector<Box>& boxes, vector<int>& from, int index) {
    if(index >= 0 && index < boxes.size()) {
        show(boxes, from, from[index]);
        cout << boxes[index].id << " ";
    }
}
int main() { _
    int n, d;

    while(cin >> n >> d) {
        vector<Box> boxes(n, {0});
        int temp;
        for(int i = 0; i < n; ++i) {
            boxes[i].id = i + 1;
            boxes[i].v.reserve(d);

            for(int j = 0; j < d; ++j) {
                cin >> temp;
                boxes[i].v.push_back(temp);
            }

            sort(boxes[i].v.begin(), boxes[i].v.end());
        }

        sort(boxes.begin(), boxes.end(), cmp);

        int dp[35] = {0};
        vector<int> from(35, -1);

        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            Box& curr = boxes[i];
            
            int maxx = 0;
            int f = -1;
            for(int j = i - 1; j >= 0; --j) {
                if(maxx > j) break;
                if(dp[j] > maxx && isBigger(curr, boxes[j])) {
                    maxx = dp[j];
                    f = j;
                }
            }
            dp[i] = maxx + 1;
            from[i] = f;
        }

        // for(int i = 0; i < n; ++i) {
        //     cout << dp[i] << " ";
        // }

        int last = 0;
        for(int i = n - 1; i >= 1; --i) {
            if(dp[i - 1] != dp[i]) {
                last = i;
                break;
            }
        }

        cout << dp[n - 1] << "\n";
        show(boxes, from, last);
        cout << "\n";
    }

    return 0;
}