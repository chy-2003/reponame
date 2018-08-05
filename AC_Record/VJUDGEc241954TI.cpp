#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 30010, MAXM = 50010;
const int INF = 1000000000;
int n, m, b[MAXN];
struct Edge {
	int x, y, z;
	Edge(int x_ = 0, int y_ = 0, int z_ = 0) { x = x_; y = y_; z = z_; return; }
};
Edge edge[MAXM];
int x, y, z;
bool cmp(Edge x, Edge y) {
	return x.z > y.z;
}
int father[MAXN];
int lp, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int ans;
int get_father(int x) {
	if(father[x] == x) return x;
	father[x] = get_father(father[x]);
	return father[x];
}
int q;

struct Node {
	int d, maxnum, minnum, max_dn, max_up;
};
Node d[MAXN][16];
int deep[MAXN];
void build_tree(int pos, int fa) {
	deep[pos] = deep[fa] + 1;
	d[pos][0].d = fa;
	d[pos][0].maxnum = b[fa];
	d[pos][0].minnum = b[fa];
	d[pos][0].max_dn = -INF;
	d[pos][0].max_up = -INF;
	for(int i = 1; i < 16; i++) {
		d[pos][i].d = d[d[pos][i - 1].d][i - 1].d;
		d[pos][i].maxnum = max(d[pos][i - 1].maxnum, d[d[pos][i - 1].d][i - 1].maxnum);
		d[pos][i].minnum = min(d[pos][i - 1].minnum, d[d[pos][i - 1].d][i - 1].minnum);
		d[pos][i].max_dn = max(d[pos][i - 1].max_dn, d[d[pos][i - 1].d][i - 1].max_dn);
		d[pos][i].max_dn = max(d[pos][i].max_dn, d[d[pos][i - 1].d][i - 1].maxnum - d[pos][i - 1].minnum);
		d[pos][i].max_up = max(d[pos][i - 1].max_up, d[d[pos][i - 1].d][i - 1].max_up);
		d[pos][i].max_up = max(d[pos][i].max_up, d[pos][i - 1].maxnum - d[d[pos][i - 1].d][i - 1].minnum);
	}
	for(int t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		build_tree(lin[t], pos);
	}
	return;
}
int get_lca(int x, int y) {
	if(deep[x] < deep[y]) swap(x, y);
	for(int i = 15; i >= 0; i--)
		if(deep[d[x][i].d] >= deep[y]) x = d[x][i].d;
	if(x == y) return x;
	for(int i = 15; i >= 0; i--)
		if(d[x][i].d != d[y][i].d) x = d[x][i].d, y = d[y][i].d;
	return d[x][0].d;
}
int recmin, recmax;
void go_up(int x, int y){
	if(x == y) return;
	recmax = max(recmax, b[x]);
	for(int i = 15; i >= 0; i--) {
		if(deep[d[x][i].d] <= deep[y]) continue;
		ans = max(ans, recmax - d[x][i].minnum);
		recmax = max(recmax, d[x][i].maxnum);
		ans = max(ans, d[x][i].max_up);
		x = d[x][i].d;
	}
	return;
}
void go_down(int x, int y){
	recmin = min(recmin, b[x]);
	for(int i = 15; i >= 0; i--) {
		if(deep[d[x][i].d] < deep[y]) continue;
		ans = max(ans, d[x][i].maxnum - recmin);
		recmin = min(recmin, d[x][i].minnum);
		ans = max(ans, d[x][i].max_dn);
		x = d[x][i].d;
	}
	return;
}
int main() {
	while(scanf("%d", &n) == 1) {
		memset(b, 0, sizeof(b));
		lp = 0;
		memset(f, 0, sizeof(f)); memset(lin, 0, sizeof(lin)); memset(nxt, 0, sizeof(nxt));
		memset(edge, 0, sizeof(edge));
		memset(deep, 0, sizeof(deep));
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i++) father[i] = i;
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		scanf("%d", &m);
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			edge[i] = Edge(x, y, z);
		}
		sort(edge + 1, edge + m + 1, cmp);
		z = 1;
		ans = 0;
		for(int i = 1; i < n; i++) {
			x = get_father(edge[z].x);
			y = get_father(edge[z].y);
			while(x == y) {
				x = get_father(edge[++z].x);
				y = get_father(edge[z].y);
			}
			ans += edge[z].z;
			father[y] = x;
			add(edge[z].x, edge[z].y);
			add(edge[z].y, edge[z].x);
			z++;
		}
		printf("%d\n", ans);

		build_tree(1, 1);
		scanf("%d", &q);
		for(int i = 1; i <= q; i++) {
			scanf("%d%d", &x, &y);
			int lca = get_lca(x, y);
			ans = 0; recmin = INF; recmax = -INF;
			go_up(y, lca);
			go_down(x, lca);
			ans = max(ans, recmax - recmin);
			printf("%d\n", ans);
		}
	}
	return 0;
}

