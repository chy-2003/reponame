#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, a[100010], b[100010], l, r, mid;

LL check(LL x){
	for(int i = 1; i <= n; i++) a[i] = b[i];
	LL t = 1, la, ti, tt;
	while(t <= n && a[t] == 0) t++;
	if(t > n) return 1;
	for(int i = 1; i <= m; i++){
		la = 0;
		ti = x;
		while(ti > 0){
			ti -= t - la;
			la = t;
			if(ti <= 0) break;
			tt = min(a[t], ti);
			ti -= tt;
			a[t] -= tt;
			while(t <= n && a[t] == 0) t++;
			if(t > n) return 1;
			if(ti <= 0) break;
		}
	}
	return 0;
}

int main(){
	scanf("%I64d%I64d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%I64d", &b[i]);
	l = 0; r = 200000000000000;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)) r = mid; else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}
