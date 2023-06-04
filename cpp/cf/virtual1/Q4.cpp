#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0)->sync_with_stdio(false);
using namespace std;

string normalize(string& s) {
    int zero = 0;
    if(s[0] == '1') return s;

    while(zero < s.size() - 1 && s[zero + 1] == '0') ++zero;
    if(zero == s.size() - 1) {
        return "0";
    }
    return s.substr(zero + 1, s.size() - zero - 1);
}

string operator | (string& s1, string& s2) {
    int l1 = s1.size(), l2 = s2.size();
    string ns(max(l1, l2), '0');

    for(int i = l1 - 1; i >= 0; --i) {
        if(s1[i] == '1') ns[ns.size() - 1 - ((l1 - 1) - i)] = '1';
    }

    for(int i = l2 - 1; i >= 0; --i) {
        if(s2[i] == '1') ns[ns.size() - 1 - ((l2 - 1) - i)] = '1';
    }
    // cout << s1 << " | " << s2 << " = " << ns << "\n";
    ns = normalize(ns);
    return ns;
}

// raw, new
bool isBetter(string& raw, string& test) {
    // cout << raw << " " << test << "\n";
    if(raw.size() == test.size()) {
        return raw < test;
    } else {
        return raw.size() < test.size();
    }
}

int main() { _

    int n = 0;
    cin >> n;
    string s;
    cin >> s;

    s = normalize(s);
    string ans = s;
    int length = 0;
    int first1 = -1, z;
    first1 = s.find('1');

    if(first1 == string::npos) {
        cout << "0\n";
        return 0;
    }

    length = strspn(s.c_str(), "1");

    string temp, temp2;
    for(int i = 0; i <= length; ++i) {
        // if(s[first1])
        temp = s.substr(first1, s.size() - first1 - i);
        temp2 = s | temp;
        // cout << s << " | " <<  temp << " = " << temp2 << "\n";
        if(isBetter(ans, temp2)) {
            ans = temp2;
        }
    }
    cout << ans << "\n";
    return 0;
}