#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

#define INF 1000000000

int dist[(1 << 19) + 1];
int teams[200001];


int main() { _
    int n, c;
    cin >> c >> n;

    int fin = (1 << 19) + 1;
    for(int i = 0; i <= fin; ++i) {
        dist[i] = INF;
    }

    string s;
    queue<int> q;

    for(int i = 0; i < n; ++i) {
        cin >> s;

        int rev = 0;
        for(int j = 0; j < c; ++j) {
            teams[i] = (teams[i] << 1) + (s[j] == 'G');
            rev = (rev << 1) + (s[j] == 'H');
        }

        q.push(rev);
        dist[rev] = 0;
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        int next;
        for(int i = 0; i < c; ++i) {
            next = curr ^ (1 << i);
            if(dist[next] == INF) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << c - dist[teams[i]] << "\n";
    }

    return 0;
}