#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;

struct info{
    int a, b;
    ll x, y;
    
    bool operator< (const info& other) {
    	return x == other.x ? y < other.y : x < other.x;
    }
};

struct info2{
    ll x, y, idx;
};

info arr[1000005];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i].a >> arr[i].b;
        arr[i].x = arr[i].a - i;
        arr[i].y = i - arr[i].b;
    }

    stack<info2> st;
    
    sort(arr, arr+n);

	st.push({arr[0].x, arr[0].y, 0});
	
    for(int i=1;i<n;i++){
    	info2 curr = {arr[i].x, arr[i].y, i};
        while(!st.empty() && st.top().y <= arr[i].y){
        	curr.y = min(curr.y, st.top().y);
            st.pop();
        }
        st.push(curr);
    }

	cout << st.size() << "\n";
 
    return 0;
}

