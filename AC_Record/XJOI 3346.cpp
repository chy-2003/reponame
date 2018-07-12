#include<bits/stdc++.h>
using namespace std;
long long n;
long long aa[5][310];
long long a[90010], b[310], c[90010];
bool find(long long x){
	long long l = 1, r = n * n, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(c[mid] < x) l = mid + 1; else r = mid;
	}
	return (c[l] == x) ? true : false;
}
int main(){
	scanf("%lld", &n);
	for(long long i = 0; i < 5; i++)
		for(long long j = 1; j <= n; j++)
			scanf("%lld", &aa[i][j]);
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++)
			a[(i - 1) * n + j] = aa[0][i] + aa[1][j];
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++)
			c[(i - 1) * n + j] = aa[2][i] + aa[3][j];
	for(long long i = 1; i <= n; i++)
		b[i] = aa[4][i];
	sort(a + 1, a + n * n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n * n + 1);
	for(long long i = 1; i <= n * n; i++)
		for(long long j = 1; j <= n; j++)
			if(find(-a[i]-b[j])){
				printf("Yes\n");
				return 0;
			}
	printf("No\n");
	return 0;
}
