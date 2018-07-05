#include<bits/stdc++.h>
using namespace std;
long long n, a[200010], s[200010], ss[4], c1, c2, c3;
long long get_(){
	ss[0] = s[c1] - s[0]; ss[1] = s[c3] - s[c1];
	ss[2] = s[c2] - s[c3]; ss[3] = s[n] - s[c2];
	long long maxnum, minnum;
	maxnum = -200000000000001;
	minnum = 200000000000001;
	for(int i = 0; i < 4; i++){
		maxnum = max(maxnum, ss[i]);
		minnum = min(minnum, ss[i]);
	}
	return maxnum - minnum;
}
void de1(int ll, int rr){
	int l = ll, r = rr - 1, mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(s[mid] - s[ll - 1] <= s[rr] - s[mid]) l = mid; else r = mid - 1;
	}
	c1 = l;
	return;
}
void de2(int ll, int rr){
	int l = ll, r = rr - 1, mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(s[mid] - s[ll - 1] <= s[rr] - s[mid]) l = mid; else r = mid - 1;
	}
	c2 = l;
	return;
}
int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	long long ans = 200000000000001;
	for(int i = 2; i <= n - 2; i++){
		c3 = i;
		de1(1, i);
		de2(i + 1, n);
		ans = min(ans, get_());
		if(c1 + 1 <= i - 1){
			c1++;
			ans = min(ans, get_());
			c1--;
		}
		if(c2 + 1 <= n - 1){
			c2++;
			ans = min(ans, get_());
			c2--;
		}
		if(c1 + 1 <= i - 1 && c2 + 1 <= n - 1){
			c1++; c2++;
			ans = min(ans, get_());
			c1--; c2--;
		}
	}
	printf("%lld", ans);
	return 0;
}
