#include <bits/stdc++.h>

#define _ cin.tie(0) -> sync_with_stdio(0);

using namespace std;
using ll = long long int;

int main(void) { _
    string three = "aiyeou";
    string ten = "bkxznhdcwgpvjqtsrlmf";

    unordered_map<char, int> thr;
    unordered_map<char, int> te;
    for(int i = 0; i < 6; ++i) {
        thr[three[i]] = i;
    }

    for(int i = 0; i < 20; ++i) {
        te[ten[i]] = i;
    }

    string in;
    string out = "";
    
    while(getline(cin, in) && !cin.eof()) {
        out = "";
        for(int i = 0; i < in.size(); ++i) {
            if((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z')) {
                char c = in[i];
                if(islower(c)) {
                    if(thr.find(c) != thr.end()) {
                        out += three[(thr[c] + 3) % 6];
                    } else {
                        out += ten[(te[c] + 10) % 20];
                    }
                } else {
                    c = tolower(c);
                    if(thr.find(c) != thr.end()) {
                        out += toupper(three[(thr[c] + 3) % 6]);
                    } else {
                        out += toupper(ten[(te[c] + 10) % 20]);
                    }
                }
                
            } else {
                out += in[i];
            }
        }
        cout << out << "\n";
    }

    return 0;
}
