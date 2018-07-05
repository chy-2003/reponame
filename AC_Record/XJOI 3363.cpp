//XJOI 3363
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n, a[200010], dep[200010];
int d[200010][20], f[200010], lin[400010], ne[400010];
LL lp, val[400010], y, z;
LL t, tip[200010], ans[200010];

void add(LL x, LL y, LL z){ lp++; val[lp] = z; lin[lp] = y; ne[lp] = f[x]; f[x] = lp; return; }

void dfs(LL father, LL id){
	d[id][0] = father;
	for(int i = 1; i < 19; i++) d[id][i] = d[d[id][i - 1]][i - 1];
	int t = f[id];
	while(t){
		if(lin[t] != father){
			dep[lin[t]] = dep[id] + val[t];
			dfs(id, lin[t]);
		}
		t = ne[t];
	}
	return;
}

LL dfs2(LL id, LL father){
	LL s = 0;
	int t = f[id];
	while(t){
		if(lin[t] != father){
			s += dfs2(lin[t], id);
		}
		t = ne[t];
	}
	ans[id] = s;
	return s + tip[id];
}

LL get_(LL x, LL y){ return abs(dep[x] - dep[y]); }

int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 2; i <= n; i++){
		scanf("%lld%lld", &y, &z);
		add(i, y, z);
		add(y, i, z);
	}
	for(int i = 0; i < 19; i++) d[1][i] = 1;
	dep[1] = 0;
	dfs(1, 1);
	for(int i = 1; i <= n; i++){
		t = i;
		while(!(t == 1 || get_(d[t][0], i) > a[i])){
			for(int j = 18; j >= 0; j--)
			 	if(get_(i, d[t][j]) <= a[i]){
			 		t = d[t][j];
			 		break;
				 }
		}
		tip[t]--; tip[i]++;
	}
	t = dfs2(1, 1);
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}
