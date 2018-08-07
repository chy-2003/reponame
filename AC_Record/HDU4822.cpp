#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
const int MAXN = 100010, MAXLOG = 18;
int n, m, x, y, z;
int lp, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int size[MAXN], dfn[MAXN], timeset;
int d[MAXN][MAXLOG];
int deep[MAXN];
void clean_up() {
	lp = 0;
	memset(deep, 0, sizeof(deep));
	memset(f, 0, sizeof(f));
	memset(size, 0, sizeof(size));
	memset(dfn, 0, sizeof(dfn));
	memset(d, 0, sizeof(d));
	timeset = 0;
	return;
}
void build_tree(int pos, int fa) {
	deep[pos] = deep[fa] + 1;
	dfn[pos] = ++timeset;
	d[pos][0] = fa;
	size[pos] = 1;
	for(int i = 1; i < MAXLOG; i++) d[pos][i] = d[d[pos][i - 1]][i - 1];
	for(int t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		build_tree(lin[t], pos);
		size[pos] += size[lin[t]];
	}
	return;
}
int get_lca(int x, int y) {
	if(deep[x] < deep[y]) swap(x, y);
	for(int i = MAXLOG - 1; i >= 0; i--) 
		if(deep[d[x][i]] >= deep[y]) x = d[x][i];
	if(x == y) return x;
	for(int i = MAXLOG - 1; i >= 0; i--) 
		if(d[x][i] != d[y][i]) {
			x = d[x][i]; y = d[y][i];
		}
	return d[x][0];
}
int jump(int pos, int step) {
	int dep = deep[pos] - step;
	for(int i = MAXLOG - 1; i >= 0; i--) 
		if(deep[d[pos][i]] >= dep) pos = d[pos][i];
	return pos;
}
int solve(int x, int y, int z) {
	int a = get_lca(x, y);
	int b = get_lca(x, z);
	int kind1, kind2, aa1, aa2, bb1, bb2;

	if(deep[x] - deep[a] >= deep[y] - deep[a]) {
		kind1 = 1;
		aa1 = jump(x, deep[x] - deep[a] - 1 - (deep[x] - deep[y]) / 2);
		aa2 = dfn[aa1] + size[aa1] - 1;
		aa1 = dfn[aa1];
	} else {
		kind1 = 2;
		aa1 = jump(y, deep[y] - deep[a] - (deep[y] - deep[x] + 1) / 2);
		aa2 = dfn[aa1] + size[aa1];
		aa1 = dfn[aa1] - 1;
	}

	if(deep[x] - deep[b] >= deep[z] - deep[b]) {
		kind2 = 1;
		bb1 = jump(x, deep[x] - deep[b] - 1 - (deep[x] - deep[z]) / 2);
		bb2 = dfn[bb1] + size[bb1] - 1;
		bb1 = dfn[bb1];
	} else {
		kind2 = 2;
		bb1 = jump(z, deep[z] - deep[b] - (deep[z] - deep[x] + 1) / 2);
		bb2 = dfn[bb1] + size[bb1];
		bb1 = dfn[bb1] - 1;
	}

//	printf("solving %d %d %d\n", x, y, z);
//	printf("kind1 = %d  kind2 = %d\n", kind1, kind2);
//	printf("aa1 = %d  aa2 = %d bb1 = %d bb2 = %d\n", aa1, aa2, bb1, bb2);
	if(kind1 == 1 && kind2 == 1) {
        if(aa2 < bb1) return 0;
        if(bb2 < aa1) return 0;
		if(aa1 <= bb1 && bb2 <= aa2) return bb2 - bb1 + 1;
		if(aa1 <= bb1 && aa2 < bb2) return aa2 - bb1 + 1;
		if(bb1 < aa1 && bb2 <= aa2) return bb2 - aa1 + 1;
		if(bb1 < aa1 && aa2 < bb2) return aa2 - aa1 + 1;
	}
	if(kind1 == 1 && kind2 == 2) {
        if(aa2 <= bb1) return aa2 - aa1 + 1;
        if(aa1 >= bb2) return aa2 - aa1 + 1;
		if(aa1 <= bb1 && bb2 <= aa2) return bb1 - aa1 + 1 + aa2 - bb2 + 1;
		if(aa1 <= bb1 && aa2 < bb2) return bb1 - aa1 + 1;
		if(bb1 < aa1 && bb2 <= aa2) return aa2 - bb2 + 1;
		if(bb1 < aa1 && aa2 < bb2) return 0;
	}
	if(kind1 == 2 && kind2 == 1) {
        if(bb2 <= aa1) return bb2 - bb1 + 1;
        if(bb1 >= aa2) return bb2 - bb1 + 1;
		if(aa1 < bb1 && bb2 < aa2) return 0;
		if(aa1 < bb1 && aa2 <= bb2) return bb2 - aa2 + 1;
		if(bb1 <= aa1 && bb2 < aa2) return aa1 - bb1 + 1;
		if(bb1 <= aa1 && aa2 <= bb2) return aa1 - bb1 + 1 + bb2 - aa2 + 1;
	}
	if(kind1 == 2 && kind2 == 2) {
        int t = 0;
        if(aa1 <= bb1) t = aa1; else t = bb1;
        if(aa2 >= bb2) t += n - aa2 + 1; else t += n - bb2 + 1;
        if(aa1 >= bb2) t += aa1 - bb2 + 1;
        if(bb1 >= aa2) t += bb1 - aa2 + 1;
        return t;
	}
}
void work() {
	clean_up();
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	build_tree(1, 1);
//	for(int i = 1; i <= n; i++) printf("DFN = %d SIZE = %d\n", dfn[i], size[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		printf("%d %d %d\n", solve(x, y, z), solve(y, x, z), solve(z, x, y));
	}
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) work();
	return 0;
}
