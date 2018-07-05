#include<bits/stdc++.h>
using namespace std;
long long n, h[100010], l[100010], r[100010];
long long stac[100010], ls = 0;
int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
	h[0] = 0; h[n + 1] = 0;
	n++;
	ls = 0;
	stac[0] = 0;
	for(int i = 1; i <= n + 1; i++){
		while(h[i] < h[stac[ls]]){
			r[stac[ls]] = i - 1;
			ls--;
		}
		l[i] = stac[ls];
		ls++;
		stac[ls] = i;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, h[i] * (r[i] - l[i]));
	printf("%lld", ans);
	return 0;
}
