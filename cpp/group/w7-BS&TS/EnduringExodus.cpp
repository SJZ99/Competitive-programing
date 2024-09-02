#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

string room;

bool f(int dis, int k) {
    int len = room.size();
    int l = 0, r = 0, cnt = 0;
    cnt += (room[0] == '0');

    while(r < len) {
        while(cnt < k && r < len) {
            r++;
            if(room[r] == '0') {
                cnt++;
            }
        }

        if(cnt == k && r - l <= dis) {
            return true;
        }

        while(cnt == k || room[l] == '1') {
            l++;
            if(room[l] == '0') {
                cnt--;
            }
        }
    }
    return false;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cin >> room;

    k++;

    int l = 0, r = n + 2, m;

    cout << f(2, k) << "\n";

    // while(u r - l > 1) {
    //     m = l + (r - l) / 2;
    //     if(f(m, k)) {
    //         r = m;
    //     } else {
    //         l = m;
    //     }
    // }
    // cout << r << "\n";
    return 0;
}
