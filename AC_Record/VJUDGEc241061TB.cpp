#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long a[2010], b[2010], n, dp[2010];
int main(){
	scanf("%lld", &n);
	long long x = 0, y = 0;
	for(long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(long long i = 1; i <= n; i++)
		if(a[i] != -1) b[a[i]] = 1;
	for(long long i = 1; i <= n; i++)
		if(a[i] == -1){
			if(b[i] == 1) x++; else y++;
		}
	dp[0] = 1;
//	printf("%lld %lld\n", x, y);
	for(long long i = 2; i <= x; i++) dp[0] = (dp[0] * i) % mod;
	for(long long i = 1; i <= y; i++){
		if(i - 1 >= 0) dp[i] = (dp[i] + (i - 1) * dp[i - 1]) % mod;
		if(i - 2 >= 0) dp[i] = (dp[i] + (i - 1) * dp[i - 2]) % mod;
		if(i - 1 >= 0) dp[i] = (dp[i] + x * dp[i - 1]) % mod;
	}
//	for(int i = 0; i <= y; i++) printf("%lld ", dp[i]); printf("\n");
	printf("%lld\n", dp[y]);
	return 0;
}
