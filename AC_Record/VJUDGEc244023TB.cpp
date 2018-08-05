#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long MAXN = 100010, MAXM = 100010;
long long T[MAXM], L[MAXM], R[MAXM], delta1[MAXM], delta2[MAXN];
long long n, m;
void clean() {
	memset(T, 0, sizeof(T));
	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(R));
	memset(delta1, 0, sizeof(delta1));
	memset(delta2, 0, sizeof(delta2));
	return;
}
void init() {
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= m; i++) scanf("%lld%lld%lld", &T[i], &L[i], &R[i]);
	delta1[m] = 1; delta1[0] = mod - 1;
	return;
}
void solve() {
	long long del = 0;
	for(long long i = m; i >= 1; i--) {
		del = (del + delta1[i]) % mod;
		if(T[i] == 1) delta2[L[i]] = (delta2[L[i]] + del) % mod, delta2[R[i] + 1] = (delta2[R[i] + 1] + mod - del) % mod; else
		if(T[i] == 2) delta1[R[i]] = (delta1[R[i]] + del) % mod, delta1[L[i] - 1] = (delta1[L[i] - 1] + mod - del) % mod;
	}
	return;
}
void output() {
	long long del = 0;
	for(long long i = 1; i <= n; i++) {
		del = (del + delta2[i]) % mod;
		printf("%lld ", del);
	}
	printf("\n");
	return;
}
void work() {
	clean();
	init();
	solve();
	output();
	return;
}
int main() {
	long long t;
	scanf("%lld", &t);
	for(long long i = 1; i <= t; i++) work();
	return 0;
}

