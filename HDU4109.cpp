#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010, MAXM = 10010;
int n, m;
int lp, f[MAXN], lin[MAXM << 1], nxt[MAXM << 1], val[MAXM << 1], x, y, z;
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
int degree[MAXN], ll, rr, q[MAXN], rec[MAXN], ans;
int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		lp = 0; memset(f, 0, sizeof(f));
		memset(degree, 0, sizeof(degree));
		memset(rec, 0, sizeof(rec));
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
			degree[y]++;
		}
		ll = 0; rr = 0;
		for(int i = 0; i < n; i++)
			if(degree[i] == 0) {
				q[++rr] = i;
				rec[i] = 1;
			}
		while(ll < rr) {
			ll++;
			for(int t = f[q[ll]]; t; t = nxt[t]) {
				rec[lin[t]] = max(rec[lin[t]], max(1, val[t] + rec[q[ll]]));
				degree[lin[t]]--;
				if(degree[lin[t]] == 0) q[++rr] = lin[t];
			}
		}
		ans = 0;
		for(int i = 0; i < n; i++) ans = max(ans, rec[i]);
		printf("%d\n", ans);
	}
	return 0;
}
