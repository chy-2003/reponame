#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const long long MAXN = 200010;
const long long mod = 1000000007;
long long n, x, y;
struct Node {
	long long x, y, pos;
};
Node a[MAXN];
bool cmp1(Node x, Node y) {
	return x.y < y.y;
}
bool cmp2(Node x, Node y) {
	return x.x < y.x || x.x == y.x && x.pos < y.pos;
}
long long pow(long long x, long long y) {
	if(y == 0) return 1;
	long long t = pow(x, y / 2);
	t = (t * t) % mod;
	if(y % 2 == 1) t = (t * x) % mod;
//	printf("pow : %lld %lld %lld\n", x, y, t);
	return t;
}
long long segment_tree_sum[MAXN << 2], segment_tree_tag[MAXN << 2];
void tagclear(long long id) { segment_tree_tag[id] = 1; }
void build(long long id, long long l, long long r) {
	tagclear(id);
	segment_tree_sum[id] = 0;
	if(l == r) return;
	long long mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	return;
}
void tagdown(long long id, long long l, long long r) {
	if(l == r) {
		tagclear(id);
		return;
	}
	segment_tree_sum[id << 1] = (segment_tree_sum[id << 1] * segment_tree_tag[id]) % mod;
	segment_tree_tag[id << 1] = (segment_tree_tag[id << 1] * segment_tree_tag[id]) % mod;
	segment_tree_sum[id << 1 | 1] = (segment_tree_sum[id << 1 | 1] * segment_tree_tag[id]) % mod;
	segment_tree_tag[id << 1 | 1] = (segment_tree_tag[id << 1 | 1] * segment_tree_tag[id]) % mod;
	tagclear(id);
	return;
}
void collect(long long id, long long l, long long r) {
	if(l == r) return;
	segment_tree_sum[id] = (segment_tree_sum[id << 1] + segment_tree_sum[id << 1 | 1]) % mod;
	return;
}
void add(long long id, long long l, long long r) {
	if(l > r) return;
	tagdown(id, l, r);
	if(l == r) {
		segment_tree_sum[id] = (segment_tree_sum[id] + y) % mod;
		return;
	}
	long long mid = l + r >> 1;
	if(x <= mid) add(id << 1, l, mid);
	if(x > mid) add(id << 1 | 1, mid + 1, r);
	collect(id, l, r);
	return;
}
long long ask(long long id, long long l, long long r) {
	if(l > r) return 0;
	tagdown(id, l, r);
	if(x <= l && r <= y) return segment_tree_sum[id];
	long long mid = l + r >> 1;
	long long t1 = 0, t2 = 0;
	if(x <= mid) t1 = ask(id << 1, l, mid);
	if(y > mid) t2 = ask(id << 1 | 1, mid + 1, r);
	return (t1 + t2) % mod;
}
void multiply(long long id, long long l, long long r) {
	if(l > r) return;
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		segment_tree_sum[id] = (segment_tree_sum[id] * 2) % mod;
		segment_tree_tag[id] = (segment_tree_tag[id] * 2) % mod;
		return;
	}
	long long mid = l + r >> 1;
	if(x <= mid) multiply(id << 1, l, mid);
	if(y > mid) multiply(id << 1 | 1, mid + 1, r);
	collect(id, l, r);
	return;
}
long long tree2[MAXN];
long long lowbit(long long x) { return x & (-x); }
long long ask2(long long x) {
	long long re = 0;
	while(x) {
		re = (re + tree2[x]) % mod;
		x -= lowbit(x);
	}
	return re;
}
void add2(int x) {
	if(x == 0) return;
	while(x <= n) {
		tree2[x] = (tree2[x] + 1) % mod;
		x += lowbit(x);
	}
	return;
}
int main() {
	while(scanf("%lld", &n) == 1) {
		memset(a, 0, sizeof(a));
		for(long long i = 1; i <= n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
		sort(a + 1, a + n + 1, cmp1);
		for(long long i = 1; i <= n; i++) a[i].pos = i;
		sort(a + 1, a + n + 1, cmp2);
//		for(long long i = 1; i <= n; i++) printf("%lld %lld %lld\n", a[i].x, a[i].y, a[i].pos);
		for(long long i = 1; i <= n; i++) a[i].x = pow(2LL, a[i].x), a[i].y = pow(3LL, a[i].y);
//		for(long long i = 1; i <= n; i++) printf("%lld %lld %lld\n", a[i].x, a[i].y, a[i].pos);
		build(1, 1, n);
		memset(tree2, 0, sizeof(tree2));
		long long ans = 0;
		for(long long i = 1; i <= n; i++) {
			x = a[i].pos; y = a[i].y * pow(2LL, ask2(x - 1)); y %= mod;
			add(1, 1, n);
			add2(x);
			x = a[i].pos; y = n;
			ans = (ans + (a[i].x * ask(1, 1, n)) % mod) % mod;
			x = a[i].pos + 1; y = n;
			multiply(1, 1, n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
