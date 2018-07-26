#include<bits/stdc++.h>
using namespace std;
int n, s;
int lp = 0, f[200010], lin[400010], nxt[400010];
int step1[200010], step2[200010];
int x, y, ans;
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
void dfs1(int fa, int pos){
	step1[pos] = step1[fa] + 1;
	for(int t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		dfs1(pos, lin[t]);
	}
	return;
}
void dfs2(int fa, int pos){
	step2[pos] = step2[fa] + 1;
	if(step2[pos] < step1[pos]) ans = max(ans, step1[pos]);
	for(int t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		dfs2(pos, lin[t]);
	}
	return;
}
int main(){
	scanf("%d%d", &n, &s);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	memset(step1, 255, sizeof(step1));
	dfs1(1, 1);
	ans = 0;
	memset(step2, 255, sizeof(step2));
	dfs2(s, s);
	printf("%d\n", ans * 2);
	return 0;
}
