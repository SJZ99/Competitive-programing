#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
#define _ cin.tie(0) -> sync_with_stdio(false);

using namespace std;
using ll = long long int;

// 0 not used
int toIndex(int p) {
	if(p > 0) {
		return 2 * p - 1;
	} else {
		return -2 * p;
	}
}

bool hasNeg = false, hasPos = false;
bool negInter = false, posInter = false;
vector<bool> vis;
vector<bool> pre;
bool zero = false;
// flag for finding intersection.
void dfs(int origin, int curr, vector<vector<int>>& adj, bool flag) {
	vis[curr] = true;
	if(curr != origin) {
		bool pos = true;
		if(curr % 2 != 0) pos = true;
		else pos = false;

		if(pos) hasPos = true;
		else hasNeg = true; 

		if(flag) {
			// find intersection
			if(pre[curr]) {
				if(pos) posInter = true;
				else negInter = true;
			}
		}

		if((origin % 2) != 0 && curr == origin + 1) {
			zero = true;
		} else if(origin % 2 == 0 && curr == origin - 1) {
			zero = true;
		}
	}

	if(posInter && negInter) return;

	for(int nei : adj[curr]) {
		if(!vis[nei]) {
			dfs(origin, nei, adj, flag);
		}
	}
}

void reset() {
	negInter = false;
	hasNeg = false;
	posInter = false;
	hasPos = false;
	zero = false;
	pre = vis;
	fill(vis.begin(), vis.end(), false);
}

int main() { _
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj1(2 * n + 1);
	vector<vector<int>> adj2(2 * n + 1);
	
	int a, b;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj1[toIndex(-a)].push_back(toIndex(b));
		adj1[toIndex(-b)].push_back(toIndex(a));
		
		adj2[toIndex(b)].push_back(toIndex(-a));
		adj2[toIndex(a)].push_back(toIndex(-b));
	}

	vis.resize(2 * n + 1);
	pre.resize(2 * n + 1);
	bool one = false, two = false, absZero = false;
	for(int i = 1; i <= 2 * n; i += 2) {
		reset();
		dfs(i, i, adj1, false);

		bool neg = hasNeg, negInte = negInter;
		bool zero1 = zero, zero2 = false;
		
		reset();
		dfs(i + 1, i + 1, adj1, true);
		neg &= hasNeg;
		negInte = negInter;
		zero2 = zero;

		// -------------------------------------
		reset();
		dfs(i, i, adj2, false);
		bool pos = hasPos;

		absZero = zero1 && zero;
		
		reset();
		dfs(i + 1, i + 1, adj2, true);
		pos &= hasPos;

		absZero |= zero2 && zero;

		if(negInte && posInter) {
			one = true;
			break;
		} else if(neg && pos) {
			two = true;
		}

		if(absZero) {
			break;
		}
	}
	if(absZero) cout << "0\n";
	else if(one) {
		cout << "1\n";
	} else if(two) {
		cout << "2\n";
	} else {
		cout << "-1\n";
	}

    return 0;
}