//XJOI 3528
#include <bits/stdc++.h>
using namespace std;
long long n, k, a[60], l, ans = 0, cnt, maxnum, t;
int main(){
	cin >> n >> k;
	l = 0;
	t = n;
	while(n){
		l++;
		a[l] = n % 2;
		n /= 2;
	}
	maxnum = 0;
	cnt = 0;
	for(int i = 1; i <= l; i++){
		if(a[i] == 0) cnt = 0; else cnt++;
		maxnum = max(maxnum, cnt);
	}
	if(maxnum >= k){
		cout << t;
		return 0;
	}
	for(int i = 1; i <= k; i++) a[i] = 1;
	l = max(l, k);
	for(int i = 1; i <= l; i++){
		if(a[i] == 0) break;
		cnt = i;
	}
	if(cnt > k)
		for(int i = 1; i <= cnt - k; i++) a[i] = 0;
	for(int i = l; i >= 1; i--){
		ans = ans * 2 + a[i];
	}
	cout << ans;
	return 0;
}