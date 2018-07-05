//XJOI 3379
#include <bits/stdc++.h>
using namespace std;
int a[100010], f[100010], g[100010], n, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		if(a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
	}
	for(int i = n; i >= 1; i--){
		g[i] = 1;
		if(a[i] < a[i + 1]) g[i] = g[i + 1] + 1;
	}
	ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	if(ans < n) ans++;
	for(int i = 1; i <= n; i++) if(a[i + 1] - a[i - 1] >= 2) ans = max(ans, f[i - 1] + g[i + 1] + 1);
	printf("%d", ans);
	return 0;
}