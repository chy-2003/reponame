#include<bits/stdc++.h>
using namespace std;
int n, val[100010];
int x, y, ans;
int lp = 0, f[100010], lin[200010], nxt[200010], len[200010];
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; len[lp] = z; f[x] = lp; return; }
void dfs(int fa, int pos, int dis){
	if(dis < 0) dis = 0;
	if(dis > val[pos]) return;
	ans++;
	for(int t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		dfs(pos, lin[t], dis + len[t]);
	}
	return;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, i + 1, y);
		add(i + 1, x, y);
	}
	ans = 0;
	dfs(0, 1, 0);
	printf("%d\n", n - ans);
	return 0;
}
