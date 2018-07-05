#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n, s, a[100010], sum[100010];
int check(int x){
	for(int i = x; i <= n; i++)
		if(sum[i] - sum[i - x] >= s) return 1;
	return 0;
}
int main(){
	scanf("%lld%lld", &n, &s);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	a[n + 1] = a[n];
	LL l = 0, r = n + 1, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)) r = mid; else l = mid + 1;
	}
	if(l < n + 1)
	printf("%lld", l); else printf("0");
	return 0;
}
