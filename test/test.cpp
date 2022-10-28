#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
    fastio

    int i[2] = {10, 20}, *ptr = i;
    cout << ++*ptr << " " << *ptr;
    return 0;
}