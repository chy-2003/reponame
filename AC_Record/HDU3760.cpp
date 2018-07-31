#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100010, MAXM = 200010;
int n, m, x, y, z;
int lp = 0, f[MAXN], lin[MAXM << 1], nxt[MAXM << 1], val[MAXM << 1];
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
int l, r, q1[MAXN], q2[MAXN];
void bfs1() {
	memset(q2, 0, sizeof(q2));
	l = 0; r = 1; q1[1] = n; q2[n] = 1;
	while(l < r) {
		l++;
		for(int i = f[q1[l]]; i; i = nxt[i]) {
			if(q2[lin[i]] != 0) continue;
			q2[lin[i]] = q2[q1[l]] + 1;
			q1[++r] = lin[i];
			if(lin[i] == 1) return;
		}
	}
	return;
}
int l1, rec1[MAXN], l2, rec2[MAXN], vis[MAXN];
int ll, recc[MAXN];
void bfs2() {
	ll = 0;
	l1 = 1; rec1[1] = 1;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	int minnum, id;
	while(1) {
		minnum = 2000000000;
		l2 = 0;
		for(int i = 1; i <= l1; i++) {
			for(int t = f[rec1[i]]; t; t =nxt[t]) {
				if(q2[lin[t]] != q2[rec1[i]] - 1) continue;
				if(val[t] < minnum) {
					minnum = val[t];
					for(int j = 1; j <= l2; j++) vis[rec2[j]] = 0;
					l2 = 1; rec2[1] = lin[t]; vis[lin[t]] = 1;
				} else
				if(val[t] == minnum && vis[lin[t]] == 0) {
					rec2[++l2] = lin[t];
					vis[lin[t]] = 1;
				}
			}
		}
		recc[++ll] = minnum;
		if(rec2[1] == n) break;
		l1 = l2;
		for(int i = 1; i <= l2; i++) rec1[i] = rec2[i];
	}
	return;
}
int main() {
	int tttt;
	scanf("%d", &tttt);
	while(tttt--) {
		scanf("%d%d", &n, &m);
		lp = 0; memset(f, 0, sizeof(f));
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z); add(y, x, z);
		}
		bfs1(); bfs2();
		printf("%d\n%d", q2[1] - 1, recc[1]);
		for(int i = 2; i <= ll; i++) printf(" %d", recc[i]);
		printf("\n");
	}
	return 0;
}
