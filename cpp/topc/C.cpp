#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;
using ull = unsigned long long int;

int main() { _
    string s;
    cin >> s;

    ull b;
    cin >> b;

    ull curr = b;
    ull temp = 0;
    ll res = 0;
    ull mul = 1;
    ll zeros = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(i == s.size() - 1) {
            if(s[i] - '0' > curr) {
                cout << "NO WAY\n";
                return 0;
            }
            temp = (s[i] - '0');
            mul *= 10;

        } else {
            if(temp + (s[i] - '0') * mul <= curr) {
                if(s[i] == '0') {
                    zeros++;
                }
                temp += (s[i] - '0') * mul;
                mul *= 10;
            } else {
                if(zeros != 0) {
                    curr = temp;
                    temp = (s[i] - '0') * (ull) round(pow(10, zeros));
                    if(temp > curr) {
                        cout << "NO WAY\n";
                        return 0;
                    }
                    mul = pow(10, zeros);
                    zeros = 0;
                    res++;
                } else {
                    res++;
                    curr = temp;
                    temp = s[i] - '0';
                    mul = 10;
                }
            }
        }
        // cout << curr << "\n";
    }
    // cout << temp << "\n";
    if(temp <= curr) {
        cout << res << "\n";
    } else {
        cout << "NO WAY\n";
    }

    return 0;
}