#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL MAXN = 5010;
const LL INF = 1000000000000000000;
LL n, x[MAXN], y[MAXN], z[MAXN];
LL lp = 0, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1];
inline void add(LL x, LL y, LL z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
LL rec;
LL s[MAXN], sum[MAXN], size[MAXN];
void dfs(LL pos, LL fa) {
//	printf("DFS%lld\n", pos);
	size[pos] = 1;
	for(LL t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		if((lin[t] == x[rec] && pos == y[rec]) || (lin[t] == y[rec] && pos == x[rec])) continue;
		dfs(lin[t], pos);
		size[pos] += size[lin[t]];
		s[pos] += s[lin[t]];
		sum[pos] += sum[lin[t]] + val[t] * size[lin[t]];
	}
	for(LL t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		if((lin[t] == x[rec] && pos == y[rec]) || (lin[t] == y[rec] && pos == x[rec])) continue;
		s[pos] += sum[lin[t]] * (size[pos] - size[lin[t]]);
		s[pos] += size[lin[t]] * val[t] * (size[pos] - 1 - size[lin[t]]);
		s[pos] += val[t] * size[lin[t]];
	}
	return;
}
LL ans, xx, yy;
void dfs1(LL pos, LL fa) {
	size[pos] = 1;
	for(LL t = f[pos]; t; t = nxt[t]) {
		if(lin[t] ==  fa) continue;
		if((lin[t] == x[rec] && pos == y[rec]) || (lin[t] == y[rec] && pos == x[rec])) continue;
		dfs1(lin[t], pos);
		size[pos] += size[lin[t]];
	}
	return;
}
void get_x(LL tot, LL pos, LL fa) {
	LL tt = tot - size[pos];
	for(LL t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		if((lin[t] == x[rec] && pos == y[rec]) || (lin[t] == y[rec] && pos == x[rec])) continue;
		get_x(tot, lin[t], pos);
		tt = max(tt, size[lin[t]]);
	}
	if(tt <= tot / 2) xx = pos;
	return;
}
void get_y(LL tot, LL pos, LL fa) {
	LL tt = tot - size[pos];
	for(LL t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		if((lin[t] == x[rec] && pos == y[rec]) || (lin[t] == y[rec] && pos == x[rec])) continue;
		get_y(tot, lin[t], pos);
		tt = max(tt, size[lin[t]]);
	}
	if(tt <= tot / 2) yy = pos;
	return;
}
int main(){
	scanf("%lld", &n);
	memset(f, 0, sizeof(f));
	for(LL i = 1; i < n; i++) {
		scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		add(x[i], y[i], z[i]);
		add(y[i], x[i], z[i]);
	}
//	printf("*\n");
	ans = INF;
	for(LL i = 1; i < n; i++) {
//		printf("%lld\n", i);
		rec = i;
		memset(s, 0, sizeof(s));
		memset(sum, 0, sizeof(sum));
		memset(size, 0, sizeof(size));
		dfs1(x[i], -1); dfs1(y[i], -1);
		get_x(size[x[i]], x[i], -1); get_y(size[y[i]], y[i], -1);
		memset(size, 0, sizeof(size));
//		printf("x == %lld y == %lld\n", xx, yy);
		dfs(xx, -1); dfs(yy, -1);
//		printf("x : s %lld sum %lld size %lld\n", s[xx], sum[xx], size[xx]);
//		printf("y : s %lld sum %lld size %lld\n", s[yy], sum[yy], size[yy]);
//		for(LL j = 1; j <= n; j++) {
//			printf("%lld : s %lld sum %lld size %lld\n", j, s[j], sum[j], size[j]);
//		}
		ans = min(ans, s[xx] + s[yy] + sum[xx] * size[yy] + sum[yy] * size[xx] + z[i] * size[xx] * size[yy]);
//		printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}

