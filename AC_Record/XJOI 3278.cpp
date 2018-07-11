#include<bits/stdc++.h>
using namespace std;
int n, sum, a[110], f[5000010], ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = sum / 2 - a[i]; j >= 0; j--)
			if(f[j] == 1 && f[j + a[i]] == 0)
				f[j + a[i]] = 1;
	ans = 2000000000;
	for(int i = sum / 2; i >= 0; i--)
		if(f[i] == 1) ans = min(sum - 2 * i, ans);
	printf("%d\n", ans);
	return 0;
}
