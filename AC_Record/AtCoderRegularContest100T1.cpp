#include<bits/stdc++.h>
using namespace std;
long long n, a[200010];
int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) a[i] -= i;
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans += abs(a[i] - a[(n + 1) / 2]);
	printf("%lld", ans);
	return 0;
}
