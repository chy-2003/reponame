#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
const long long MAXN = 100010, MAXM = 300010;
struct Node {
	long long x, y, z;
	Node(long long x_ = 0, long long y_ = 0, long long z_ = 0) {
		x = x_; y = y_; z = z_; return;
	}
};
bool cmp(Node x, Node y) { return x.z < y.z; }
Node edge[MAXM];
long long x, y, z;
long long n, m;
long long t;
long long father[MAXN];
long long rec[MAXM];
long long ans = 0;
long long deep[MAXN];
long long lp = 0, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1];
inline void add(long long x, long long y, long long z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
long long get_father(long long x){
	if(father[x] == x) return x;
	father[x] = get_father(father[x]);
	return father[x];
}


long long d[MAXN][20], first[MAXN][20], second[MAXN][20];

long long get_first(long long a, long long b, long long c, long long d){
	long long ret = -INF;
	ret = max(ret, a);
	ret = max(ret, b);
	ret = max(ret, c);
	ret = max(ret, d);
	return ret;
}
long long get_second(long long a, long long b, long long c, long long d, long long e){
	long long ret = -INF;
	if(a != e) ret = max(ret, a);
	if(b != e) ret = max(ret, b);
	if(c != e) ret = max(ret, c);
	if(d != e) ret = max(ret, d);
	return ret;
}
void build(long long pos, long long fa){
	deep[pos] = deep[fa] + 1;
	d[pos][0] = fa;
	for(long long i = 1; i < 20; i++) d[pos][i] = d[d[pos][i - 1]][i - 1];
	for(long long i = 1; i < 20; i++){
		first[pos][i] = get_first(first[pos][i - 1], first[d[pos][i - 1]][i - 1],
				second[pos][i - 1], second[d[pos][i - 1]][i - 1]);
		second[pos][i] = get_second(first[pos][i - 1], first[d[pos][i - 1]][i - 1], 
				second[pos][i - 1], second[d[pos][i - 1]][i - 1], first[pos][i]);
	}
	for(long long t = f[pos]; t; t = nxt[t]){
		if(lin[t] == fa) continue;
		first[lin[t]][0] = val[t];
		second[lin[t]][0] = -INF;
		build(lin[t], pos);
	}
	return;
}
long long ans1, t1, t2;


void doit(long long x, long long y){
	if(deep[x] < deep[y]) swap(x, y);
	for(long long i = 19; i >= 0; i--)
		if(deep[d[x][i]] >= deep[y]){
			t1 = get_first(t1, t2, first[x][i], second[x][i]);
			t2 = get_second(t1, t2, first[x][i], second[x][i], t1);
			x = d[x][i];
		}
	if(x == y) return;
	for(long long i = 19; i >= 0; i--)
		if(d[x][i] != d[y][i]){
			t1 = get_first(t1, t2, first[x][i], second[x][i]);
			t2 = get_second(t1, t2, first[x][i], second[x][i], t1);
			t1 = get_first(t1, t2, first[y][i], second[y][i]);
			t2 = get_second(t1, t2, first[y][i], second[y][i], t1);
			x = d[x][i]; y = d[y][i];
		}
	t1 = get_first(t1, t2, first[x][0], second[x][0]);
	t2 = get_second(t1, t2, first[x][0], second[x][0], t1);
	t1 = get_first(t1, t2, first[y][0], second[y][0]);
	t2 = get_second(t1, t2, first[y][0], second[y][0], t1);
	return;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		edge[i] = Node(x, y, z);
	}
	sort(edge + 1, edge + m + 1, cmp);
	for(long long i = 1; i <= n; i++) father[i] = i;
	t = 1;
	memset(rec, 0, sizeof(rec));
	for(long long i = 1; i < n; i++) {
		x = get_father(edge[t].x); 
		y = get_father(edge[t].y);
		while(x == y){
			t++;
			x = get_father(edge[t].x);
			y = get_father(edge[t].y);
		}
		father[y] = x;
		add(edge[t].x, edge[t].y, edge[t].z);
		add(edge[t].y, edge[t].x, edge[t].z);
		ans += edge[t].z;
		rec[t] = 1;
		t++;
	}
	//printf("%lld\n", ans);
	ans1 = INF;
	first[1][0] = -INF; second[1][0] = -INF;
	memset(deep, 0, sizeof(deep));
	build(1, 1);
	for(long long i = 1; i <= m; i++){
		if(rec[i]) continue;
		t1 = -INF; t2 = -INF;
		doit(edge[i].x, edge[i].y);
		//printf("edge = %lld -> %lld : %lld, t1 = %lld, t2 = %lld\n", edge[i].x, edge[i].y, edge[i].z, t1, t2);
		if(t1 != edge[i].z) ans1 = min(ans1, ans + edge[i].z - t1); else ans1 = min(ans1, ans + edge[i].z - t2);
	}
	printf("%lld\n", ans1);
	return 0;
}

