#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

int main() {
    ll a, b;
	while(cin >> a >> b) {
		if(a > b) swap(a, b);
		ll tmp = sqrt(b);
		ll ans = 0;
		for(ll i = 1; i <= tmp; ++i) {
            // a - 1 for i | a
			ans += i * (b / i - (a - 1) / i);

            // small than sqrt(b) will be calcuated at above
			ll tmp1 = max(tmp, (a - 1) / i);
			ll tmp2 = max(tmp, b / i);

            // b * (b+1) / 2 - a * (a + 1) / 2
            // sum from a+1 to b
            ans += (tmp2 * tmp2 + tmp2 - tmp1 * tmp1 - tmp1) / 2;
            // ans += ((tmp2 * (tmp2 + 1) / 2) - (tmp1 * (tmp1 + 1) / 2));
		}
		cout << ans << "\n";
	}
}