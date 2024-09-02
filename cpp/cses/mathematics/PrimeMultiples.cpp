#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
	ll n;
	int k;
	cin >> n >> k;
	
	ll arr[k] = {};
	for(int i = 0; i < k; ++i) {
		cin >> arr[i];
	}
	
	ll end = (1 << k) - 1;
	ll cnts[k+1] = {};
	for(int i = 1; i <= end; ++i) {
		int cnt = 0;
		ll prod = 1;
		bool big = false;
		
		for(int j = 0; j < k; ++j) {
			if(i & (1 << j)) {
				cnt++;
				if(LLONG_MAX / arr[j] < prod) {
					big = true;
					break;
				}
				prod *= arr[j];
			}
 		}
 		
 		if(!big) {
	 		cnts[cnt] += n / prod;
	 	}
	} 
	
	ll res = 0;
	for(int i = 1; i <= k; ++i) {
		if(i & 1) {
			res += cnts[i];
		} else {
			res -= cnts[i];
		}
	}
	cout << res << "\n";
	return 0;
}
