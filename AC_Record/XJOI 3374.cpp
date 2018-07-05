//XJOI 3374
#include <bits/stdc++.h>
using namespace std;
int a[2010], n, f[2010], g[2010], max1, max2, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if(a[i] == 1) f[i]++;
		if(a[i] == 2) g[i]++;
	}
	ans = 0;
	for(int i = 0; i <= n; i++){
		max1 = 0;
		for(int j = 0; j <= i; j++) max1 = max(max1, f[j] - f[0] + g[i] - g[j]);
		max2 = 0;.
		for(int j = i; j <= n; j++) max2 = max(max2, f[j] - f[i] + g[n] - g[j]);
		ans = max(ans, max1 + max2);
	}
	printf("%d", ans);
	return 0;
}