#include<bits/stdc++.h>
using namespace std;
struct Edge{
	long long from, to, val;
	Edge(long long from_ = 0, long long to_ = 0, long long val_ = 0) { from = from_; to = to_; val = val_; return; }
};
const long long MAXM = 200010, MAXN = 200010, INF = 1000000000000000000;
long long n, m;
long long x, y, z;
long long ll;
Edge edge[MAXM];

bool cmp(Edge x, Edge y){ return x.val < y.val; }




long long lp = 0, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], value[MAXN << 1];
void add(long long x, long long y, long long z) { nxt[++lp] = f[x]; f[x] = lp; lin[lp] = y; value[lp] = z; return; }
long long father[MAXN];



long long get_father(long long x){
	if(father[x] == x) return x;
	father[x] = get_father(father[x]);
	return father[x];
}


int edge_used[MAXM];



const long long MAXLOG = 20;
long long b[MAXN][MAXLOG], maxnum[MAXN][MAXLOG], deep[MAXN];
void build_tree(long long fa, long long pos, long long s){
	deep[pos] = deep[fa] + 1;
	b[pos][0] = fa;
	for(long long i = 1; i < MAXLOG; i++) b[pos][i] = b[b[pos][i - 1]][i - 1];
	maxnum[pos][0] = s;
	for(long long i = 1; i < MAXLOG; i++) maxnum[pos][i] = max(maxnum[pos][i - 1], maxnum[b[pos][i - 1]][i - 1]); 
	for(long long t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		build_tree(pos, lin[t], value[t]);
	}
	return;
}
long long get_lca(long long x, long long y){
	if(deep[x] < deep[y]) swap(x, y);
	for(long long i = MAXLOG - 1; i >= 0; i--) 
		if(deep[b[x][i]] >= deep[y]){
			x = b[x][i];
		}
	if(x == y) return x;
	for(long long i = MAXLOG - 1; i >= 0; i--)
		if(b[x][i] != b[y][i]) x = b[x][i], y = b[y][i];
	return b[x][0];
}
long long get_(long long x, long long y){
	long long t = 0;
	for(long long i = MAXLOG - 1; i >= 0; i--)
		if(deep[b[x][i]] >= deep[y]){
			t = max(t, maxnum[x][i]);
			x = b[x][i];
		}
	return t;
}


int main(){
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= m; i++){
		scanf("%lld%lld%lld", &x, &y, &z);
		edge[i] = Edge(x, y, z);
	}
	sort(edge + 1, edge + m + 1, cmp);
	for(long long i = 1; i <= n; i++) father[i] = i;
	ll = 1;
	long long ans1 = 0;
	for(long long i = 1; i < n; i++){
		long long xx = get_father(edge[ll].from);
		long long yy = get_father(edge[ll].to);
		while(xx == yy){
			ll++;
			xx = get_father(edge[ll].from);
			yy = get_father(edge[ll].to);
		}
		father[yy] = xx;
		ans1 += edge[ll].val;
		edge_used[ll] = 1;
		add(edge[ll].from, edge[ll].to, edge[ll].val);
		add(edge[ll].to, edge[ll].from, edge[ll].val);
	}
	printf("%lld ", ans1);



	long long ans2 = INF;
	build_tree(1, 1, 0);
	for(long long i = 1; i <= m; i++){
		if(edge_used[i]) continue;
		long long t = ans1 + edge[i].val;
		long long lca = get_lca(edge[i].from, edge[i].to);
		long long t1 = get_(edge[i].from, lca);
		long long t2 = get_(edge[i].to, lca);
		t -= max(t1, t2);
		ans2 = min(ans2, t);
	}
	printf("%lld\n", ans2);
	return 0;
}

