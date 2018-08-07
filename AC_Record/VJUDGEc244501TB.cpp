#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long MAXN = 100010;
long long segment_tree_sum[MAXN << 2], segment_tree_tag[MAXN << 2];
long long n, a[MAXN], m, x, y, z;
char ch;
void build(long long id, long long l, long long r) {
	if(l == r) {
		segment_tree_sum[id] = a[l];
		return;
	}
	long long mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 ^ 1, mid + 1, r);
	segment_tree_sum[id] = segment_tree_sum[id << 1] + segment_tree_sum[id << 1 ^ 1];
	return;
}
void tagdown(long long id, long long l, long long r) {
	if(l == r) {
		segment_tree_tag[id] = 0;
		return;
	}
	long long mid = l + r >> 1;
	segment_tree_sum[id << 1] += (mid - l + 1) * segment_tree_tag[id];
	segment_tree_tag[id << 1] += segment_tree_tag[id];
	segment_tree_sum[id << 1 ^ 1] += (r - mid) * segment_tree_tag[id];
	segment_tree_tag[id << 1 ^ 1] += segment_tree_tag[id];
	segment_tree_tag[id] = 0;
	return;
}
long long ask(long long id, long long l, long long r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) return segment_tree_sum[id];
	long long mid = l + r >> 1;
	long long t1 = 0, t2 = 0;
	if(x <= mid) t1 = ask(id << 1, l, mid);
	if(y > mid) t2 = ask(id << 1 ^ 1, mid + 1, r);
	return t1 + t2;
}
void change(long long id, long long l, long long r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		segment_tree_sum[id] += (r - l + 1) * z;
		segment_tree_tag[id] = z;
		return;
	}
	long long mid = l + r >> 1;
	if(x <= mid) change(id << 1, l, mid);
	if(y > mid) change(id << 1 ^ 1, mid + 1, r);
	segment_tree_sum[id] = segment_tree_sum[id << 1] + segment_tree_sum[id << 1 ^ 1];
	return;
}
int main() {
	while(scanf("%lld%lld", &n, &m) == 2) {
		memset(segment_tree_sum, 0, sizeof(segment_tree_sum));
		memset(segment_tree_tag, 0, sizeof(segment_tree_tag));
		for(long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
		build(1, 1, n);
		for(long long i = 1; i <= m; i++) {
			ch = getchar();
			while(ch != 'Q' && ch != 'C') ch = getchar();
			if(ch == 'Q') {
				scanf("%lld%lld", &x, &y);
				printf("%lld\n", ask(1, 1, n));
			}
			if(ch == 'C') {
				scanf("%lld%lld%lld", &x, &y, &z);
				change(1, 1, n);
			}
		}
	}
	return 0;
}
