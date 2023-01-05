#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);
using namespace std;

struct matrix {
    long long int m;
    long long int n;

    long long int operator * (const struct matrix& ma) const {
        return this->m * this->n * ma.n;
    }

    struct matrix operator + (const struct matrix& mend) const {
        return {this->m, mend.n};
    }

};

typedef struct matrix matrix;

unordered_map<int, int> recorder;

void appendUpBracket(int i, char* res) {
    char temp[200];
    sprintf(temp, "%d", i + 1);
    char* ptr = strpbrk(res, temp);
    int len = strlen(ptr - 1);
    memmove(ptr, ptr - 1, len);
    *(ptr - 1) = '(';
}

void appendDownBracket(int i, char* res) {
    char temp[200];
    sprintf(temp, "%d", (i + 1) % 10);
    char* ptr = strpbrk(res, temp);
    int len = strlen(ptr + 1);
    memmove(ptr + 2, ptr + 1, len);
    *(ptr + 1) = ')';
}

void dfs(int target, char* res) {
    int f = target / 10;
    int t = target % 10;
    // cout << f << " " << t << "\n";
    if(t - f >= 1) {
        appendUpBracket(f, res);
        appendDownBracket(t, res);
        if(t - f == 1) {
            return;
        }
        int next = recorder[target];
        // recorder[target] = 0;
        // cout << next << "\n";
        int nf = next / 10, nt = next % 10;
        int anotherNext = 0;
        if(nf == f) {
            anotherNext = (nt + 1) * 10 + t;
        } else {
            anotherNext = f * 10 + nt - 1;
        }

        // cout << next << " " << anotherNext << "\n";
        dfs(next, res);
        dfs(anotherNext, res);
    }    
}

int main() { _
    int n;
    cin >> n;
    int cases = 1;

    while(n != 0) {
        matrix arr[n];
        int a, b;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            arr[i] = {a, b};
        }

        long long int dp[n][n] = {0};
        recorder.clear();

        for(int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = arr[i] * arr[i + 1];
        }

        

        // how many matrix will be appended
        for(int i = 2; i < n; ++i) {

            // from who            
            for(int j = 0; j < n - i; ++j) {
                long long int mm = LONG_LONG_MAX;
                int mk = -1;
                int temp;
                // cut where
                for(int k = j; k < j + i; ++k) {
                    // cout << i << " " << j << " " << k << "\n";
                    temp = dp[k + 1][j + i] + dp[j][k] + (arr[j] + arr[k]) * (arr[k + 1] + arr[j + i]);
                    if(temp < mm) {
                        mm = temp;
                        mk = k;
                    }
                    // cout << dp[k + 1][j + i] + dp[j][k] + (arr[j] + arr[k]) * (arr[k + 1] + arr[j + i]) << " ";
                }
                recorder.insert({j * 10 + j + i, j * 10 + mk});
                dp[j][j + i] = mm;
                // cout << "\n";
            }
        }       

        // for(auto p : recorder) {
        //     cout << p.first / 10 << "~" << p.first % 10 << " from " << p.second / 10 << "~" << p.second % 10 << "\n";
        // } 

        char res[2000] = {0};
        char tres[100] = {0};
        for(int i = 1; i <= n; ++i) {
            sprintf(tres, "A%d\0", i);
            strcat(res, tres);
            if(i != n) {
                strcat(res, " x ");
            }
        }

        dfs(n - 1, res);

        cout << "Case "  << cases << ": " << res << "\n";
        // cout << dp[0][n-1] << "\n";

        cin >> n;
        cases++;
    }

    return 0;
}