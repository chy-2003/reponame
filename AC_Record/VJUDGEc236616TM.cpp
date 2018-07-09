#include<bits/stdc++.h>
using namespace std;
long long n, a[100010], b[100010], c[100010], size[100010], t;
long long lp = 0, f[100010], nex[200010], lin[200010];
long long m, x, y;
double base, ans = 0.0;
void add(long long x, long long y){ lp++; nex[lp] = f[x]; lin[lp] = y; f[x] = lp; return; }
void tree_build(long long father, long long id){
	long long t = f[id];
	while(t){
		if(lin[t] != father){
			tree_build(id, lin[t]);
			size[id] += size[lin[t]];
		}
		t = nex[t];
	}
	size[id]++;
	return;
}
long long get_(long long x, long long y){
	return min(size[x], size[y]);
}
int main(){
	scanf("%lld", &n);
	base = 6.0 / (n * (n - 1));
	for(long long i = 1; i < n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	for(long long i = 1; i < n; i++){ add(a[i], b[i]); add(b[i], a[i]); }
	memset(size, 0, sizeof(size));
	tree_build(1, 1);
	for(long long i = 1; i < n; i++){
		t = get_(a[i], b[i]);
		ans += t * (n - t) * c[i];
	}
	scanf("%lld", &m);
	for(long long i = 1; i <= m; i++){
		scanf("%lld%lld", &x, &y);
		t = get_(a[x], b[x]);
		ans += t * (n - t) * (y - c[x]);
		c[x] = y;
		printf("%.10lf\n", ans * base);
	}
	return 0;
}
