#include<bits/stdc++.h>
using namespace std;
int n, val[200010];
int x, y;
int lp = 0, f[200010], lin[400010], nxt[400010], p[200010];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
set<int> ms[200010];
int gcd(int x, int y){
	int m = x % y;
	while(m){
		x = y; y = m; m = x % y;
	}
	return y;
}
void dfs(int fa, int pos){
	if(fa == 0){
		p[pos] = val[pos];
		ms[pos].insert(val[pos]);
		ms[pos].insert(0);
	} else {
		p[pos] = gcd(p[fa], val[pos]);
		ms[pos].insert(p[fa]);
		for(set<int>::iterator it = ms[fa].begin(); it != ms[fa].end(); ++it){
			ms[pos].insert(gcd(*it, val[pos]));
		}
	}
	for(int t = f[pos]; t; t = nxt[t]) 
		if(lin[t] != fa)
			dfs(pos, lin[t]);
	return;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs(0, 1);
	for(int i = 1; i <= n; i++){
		set<int>::iterator it = ms[i].end();
		--it;
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}
