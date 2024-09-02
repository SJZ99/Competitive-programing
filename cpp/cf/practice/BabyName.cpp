#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int maxn = 200005;
int sa[maxn], rk[maxn << 1], oldrk[maxn << 1], id[maxn], cnt[maxn];
void build_sa(string str) {
    int n = str.size() - 1;
    int m = max(n, 300);
    memset(cnt, 0, sizeof(cnt));
    memset(rk, 0, sizeof(rk));

    for (int i = 1; i <= n; i++) ++cnt[rk[i] = (int)str[i]];
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1; w < n; w <<= 1) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) id[i] = sa[i];
        for (int i = 1; i <= n; i++) ++cnt[rk[id[i] + w]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i] + w]]--] = id[i];

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) id[i] = sa[i];
        for (int i = 1; i <= n; i++) ++cnt[rk[id[i]]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        memcpy(oldrk, rk, sizeof(rk));
        for (int p = 0, i = 1; i <= n; i++) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                rk[sa[i]] = p;
            else
                rk[sa[i]] = ++p;
        }
    }
}

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    s1 = " "+s1;
    s2 = " "+s2; 

    build_sa(s1);
    int a = sa[s1.size() - 1];

    build_sa(s2);
    int b = sa[s2.size() - 1];

    int a2 = a;
    for(int i = a+1; i < s1.size(); ++i) {
        if(s1[i] >= s2[b]) {
            a2++;
        } else {
            break;
        }
    }
    cout << s1.substr(a, a2-a+1) << s2.substr(b) << "\n";
    return 0;
}
