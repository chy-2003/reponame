#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int lp, f[10010], lin[200010], nxt[200010];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int a[10010], b[10010];
int ti, ans;
int rec[10010];
void dfs(int pos, int fa) {
	int son = 0;
	a[pos] = ++ti;
	b[pos] = a[pos];
	for(int t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		if(a[lin[t]] == 0) {
			son++;
			dfs(lin[t], pos);
			b[pos] = min(b[pos], b[lin[t]]);
			if((a[pos] <= b[lin[t]] && pos != 1) || (pos == 1 && son > 1)) rec[pos] = 1;
		} else
			b[pos] = min(b[pos], a[lin[t]]);
	}
	return;
}
int x, y;
int main() {
	while(scanf("%d", &n) && n) {
		lp = 0;
		memset(f, 0, sizeof(f));
		memset(lin, 0, sizeof(lin));
		memset(nxt, 0, sizeof(nxt));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(rec, 0, sizeof(a));
		ti = 0;
		ans = 0;
		while(scanf("%d", &x) && x)
			while(getchar() != '\n') {
				scanf("%d", &y);
				add(x, y); add(y, x);
			}
		dfs(1, -1);
		for(int i = 1; i <= n; i++) if(rec[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}

