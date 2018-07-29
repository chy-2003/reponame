#include<bits/stdc++.h>
using namespace std;
int n;
int lp = 0, f[200010], lin[400010], nxt[400010], id[400010];
inline void add(int x, int y, int pos) { lin[++lp] = y; nxt[lp] = f[x]; id[lp] = pos; f[x] = lp; return; }
int d[200010][20], deep[200010];
int rec[200010], ans[200010];
int recc[200010];
void dfs(int fa, int pos){
	d[pos][0] = fa;
	deep[pos] = deep[fa] + 1;
	for(int i = 1; i < 20; i++) d[pos][i] = d[d[pos][i - 1]][i - 1];
	for(int t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		recc[lin[t]] = id[t];
		dfs(pos, lin[t]);
	}
	return;
}
int m;
int x, y;
int lca(int x, int y){
	if(deep[x] < deep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--)
		if(deep[d[x][i]] >= deep[y]) x = d[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(d[x][i] != d[y][i]){
			x = d[x][i]; y = d[y][i];
		}
	return d[x][0];
}
void dfs2(int fa, int pos){
	for(int t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		dfs2(pos, lin[t]);
		rec[pos] += rec[lin[t]];
	}
	ans[recc[pos]] = rec[pos];
	return;
}
int main(){
	scanf("%d", &n);
	memset(rec, 0, sizeof(rec));
	memset(recc, 0, sizeof(recc));
	memset(f, 0, sizeof(f));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, y, i);
		add(y, x, i);
	}
	dfs(0, 1);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		++rec[x]; ++rec[y]; rec[lca(x, y)] -= 2;
	}
	dfs2(0, 1);
	for(int i = 1; i < n; i++) printf("%d ", abs(ans[i])); printf("\n");
	return 0;
}
