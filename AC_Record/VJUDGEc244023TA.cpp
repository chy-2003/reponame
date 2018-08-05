#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long MAXN = 100010, MAXM = 100010, MAXC = 1010;
long long n, m, c, U[MAXC], L[MAXC], x, dp[MAXC][MAXC];
int main() {
	scanf("%lld%lld%lld", &n, &m, &c);
	memset(U, 0, sizeof(U));
	memset(L, 0, sizeof(L));
	for(long long i = 1; i <= n; i++) { scanf("%lld", &x); U[x]++; }
	for(long long i = 1; i <= m; i++) { scanf("%lld", &x); L[x]++; }
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= c; i++) {
		dp[i][0] = (dp[i - 1][0] + U[i] * L[i] % mod) % mod;
		for(int j = 1; j <= c; j++) 
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * U[i] % mod * L[i] % mod) % mod;
	}
	for(int i = 1; i <= c; i++) printf("%lld ", dp[c][i]); printf("\n");
	return 0;
}
