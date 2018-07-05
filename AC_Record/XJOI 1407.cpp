//XJOI 1407
#include <bits/stdc++.h>
using namespace std;
int a[7], n, t;
string s;
int main(){
	for(int i = 1; i <= 6; i++) a[i] = i;
	cin >> n;
	int ans = a[1];
	for(int i = 1; i <= n; i++){
		cin >> s;
		if(s == "North"){
			t = a[1];
			a[1] = a[2]; a[2] = a[6]; a[6] = a[5]; a[5] = t;
		} else
		if(s == "East"){
			t = a[1];
			a[1] = a[4]; a[4] = a[6]; a[6] = a[3]; a[3] = t;
		} else
		if(s == "West"){
			t = a[1];
			a[1] = a[3]; a[3] = a[6]; a[6] = a[4]; a[4] = t;
		} else
		if(s == "South"){
			t = a[1];
			a[1] = a[5]; a[5] = a[6]; a[6] = a[2]; a[2] = t;
		} else
		if(s == "Right"){
			t = a[2];
			a[2] = a[3]; a[3] = a[5]; a[5] = a[4]; a[4] = t;
		} else
		if(s == "Left"){
			t = a[3];
			a[3] = a[2]; a[2] = a[4]; a[4] = a[5]; a[5] = t;
		}
		ans += a[1];
	}
	cout << ans;
	return 0;
}