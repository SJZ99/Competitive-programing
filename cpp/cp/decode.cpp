#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;

int main() {
    int x = 0;
    scanf("%d", &x);
    // printf("%d", x);

    char arr[200] = {0};
    sprintf(arr, "%X", x);
    int len = strlen(arr);

    char table[100] = {0};
    table['0'] = '!',
    table['1'] = '#',
    table['2'] = '$',
    table['3'] = '%',
    table['4'] = '*', 
    table['5'] = '+', 
    table['6'] = '-', 
    table['7'] = '.', 
    table['8'] = '<', 
    table['9'] = '>', 
    table['A'] = '?', 
    table['B'] = '@', 
    table['C'] = '[', 
    table['D'] = ']', 
    table['E'] = '{', 
    table['F'] = '}';

    char res[20] = {0};
    for(int i = 0; i < len; ++i) {
        res[i] = table[arr[i]];
    }
    printf("%s\n", res);

    return 0;
}