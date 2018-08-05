#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010, MAXM = 20010;
int n, m, ans;
int deep[MAXN], father[MAXN];
int lp, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1];
inline void add(int x, int y) {lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return;}
int x, y;
int rec[MAXN];
void dfs(int pos, int fa) {
	father[pos] = fa;
	deep[pos] = deep[fa] + 1;
	for(int t = f[pos]; t; t = nxt[t]) {
		if(lin[t] == fa) continue;
		dfs(lin[t], pos);
	}
	return;
}
struct Node{
	int x, y;
	Node(int x_ = 0, int y_ = 0) {
		x = x_; y = y_; return;
	}
};
Node recc[MAXM];
bool cmp(Node x, Node y) {
	return min(deep[x.x], deep[x.y]) > min(deep[y.x], deep[y.y]);
}
int main() {
	scanf("%d%d", &n, &m);
	while(n | m) {
		lp = 0; memset(f, 0, sizeof(f));
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			add(x, y); add(y, x);
		}
		memset(father, 0, sizeof(father));
		memset(deep, 0, sizeof(deep));
		dfs(1, 0);
		ans = 0;
		memset(rec, 0, sizeof(rec));
		for(int i = n; i <= m; i++) {
			scanf("%d%d", &x, &y);
			recc[i] = Node(x, y);
		}
		sort(recc + n, recc + m + 1, cmp);
		for(int i = n; i <= m; i++) {
			x = recc[i].x; y = recc[i].y;
			if(deep[x] < deep[y]) swap(x, y);
			while(father[x] != y) 
				if(rec[x]) break; else x = father[x];
			if(rec[x] == 0) {
				ans++;
				rec[x] = 1;
			}
		}
		printf("%d\n", ans);
		scanf("%d%d", &n, &m);
	}
	return 0;
}
