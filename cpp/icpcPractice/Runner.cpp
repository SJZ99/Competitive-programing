#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <chrono>
#include "Q1.h"
#define fastio ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
using namespace std::chrono;

int main() {
    fastio

    // cin redirect
    string inputP = "C:\\Users\\9987j\\Desktop\\C-vscode\\cpp\\icpcPractice\\testdata\\A\\data\\secret\\";
    long long int time = 0;
    int from = 1, to = 48;
    for(int a = from; a <= to; ++a) {

        string inputPath = inputP + ((a <= 9) ? ("0" + to_string(a)) : to_string(a));
        ifstream input(inputPath + ".in");
        cin.rdbuf(input.rdbuf());

        // cout redirect
        auto origin = cout.rdbuf();
        ofstream output("output.txt");
        cout.rdbuf(output.rdbuf());
        uint64_t startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        
        solve();

        uint64_t endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time += (endTime - startTime);

        input.close();
        output.close();

        cout.rdbuf(origin);
        

        // tell
        char s1[100000], s2[100000];
        int i=0, j=0;

        ifstream o("output.txt");
        cin.rdbuf(o.rdbuf());
        while(cin >> s1[i++]);
        o.close();

        ifstream ans(inputPath + ".ans");
        cin.rdbuf(ans.rdbuf());
        while(cin >> s2[j++]);
        ans.close();

        for(int k=0; k<i; k++){
            if(s1[k] != s2[k]){
                cout << "WA\nin test data: " << a;
                return 0;
            }
        }
    }
    
    cout << "run time : " << time << '\n';
    cout << "AC\n";

    return 0;
}