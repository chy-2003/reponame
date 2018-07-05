//XJOI 3496
#include <bits/stdc++.h>
using namespace std;
long long n, size, m, a[1010], ans, lim;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	scanf("%lld%lld%lld", &n, &size, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++)
		if(a[i] == m){
			printf("1");
			return 0;		
		}
	sort(a + 1, a + n + 1, cmp);
	ans = 0;
	lim = n * size + 1;
	for(int i = 1; i <= n; i++){
//		printf("%lld %lld\n", lim, a[i]);
		if(a[i] <= m && lim > m) ans++;
		if((n * size - a[i] + 1) == size * i) lim = n * size - size * i + 1;
		if(lim <= m) break;
	}
	printf("%lld", ans);
	return 0;
}