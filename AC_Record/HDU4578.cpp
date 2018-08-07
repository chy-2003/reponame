#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
const LL mod = 10007;
const LL MAXN = 100010;
LL n, m, k, x, y, d;
struct Node {
	LL one, two, three, tip1, tip2, istip3, tip3;
};
Node segment_tree[MAXN << 2];
void tipclear(int id) {
	segment_tree[id].tip1 = 1;
	segment_tree[id].tip2 = 0;
	segment_tree[id].istip3 = 0;
	return;
}
void tagdown(LL id, LL l, LL r) {
	if(l == r) {
		tipclear(id);
		return;
	}
	Node t = segment_tree[id];
	LL mid = l + r >> 1;
//	printf("STATES BEFORE TAGDOWN\n");
//	printf("ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
//	printf("LC = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id << 1, l, mid, segment_tree[id << 1].one, segment_tree[id << 1].two, segment_tree[id << 1].three, segment_tree[id << 1].tip1, segment_tree[id << 1].tip2, segment_tree[id << 1].istip3, segment_tree[id << 1].tip3);
//	printf("RC = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id << 1 ^ 1, mid + 1, r, segment_tree[id << 1 ^ 1].one, segment_tree[id << 1 ^ 1].two, segment_tree[id << 1 ^ 1].three, segment_tree[id << 1 ^ 1].tip1, segment_tree[id << 1 ^ 1].tip2, segment_tree[id << 1 ^ 1].istip3, segment_tree[id << 1 ^ 1].tip3);
	if(t.istip3) {
		segment_tree[id << 1].one = (mid - l + 1) % mod * t.tip3 % mod;
		segment_tree[id << 1].two = segment_tree[id << 1].one * t.tip3 % mod;
		segment_tree[id << 1].three = segment_tree[id << 1].two * t.tip3 % mod;
		tipclear(id << 1);
		segment_tree[id << 1].istip3 = 1;
		segment_tree[id << 1].tip3 = t.tip3;
		segment_tree[id << 1 ^ 1].one = (r - mid) % mod * t.tip3 % mod;
		segment_tree[id << 1 ^ 1].two = segment_tree[id << 1 ^ 1].one * t.tip3 % mod;
		segment_tree[id << 1 ^ 1].three = segment_tree[id << 1 ^ 1].two * t.tip3 % mod;
		tipclear(id << 1 ^ 1);
		segment_tree[id << 1 ^ 1].istip3 = 1;
		segment_tree[id << 1 ^ 1].tip3 = t.tip3;
	}
	LL d = t.tip1;
	segment_tree[id << 1].one = segment_tree[id << 1].one * d % mod;
	segment_tree[id << 1].two = segment_tree[id << 1].two * d % mod * d % mod;
	segment_tree[id << 1].three = segment_tree[id << 1].three * d % mod * d % mod * d % mod;
	segment_tree[id << 1].tip1 = segment_tree[id << 1].tip1 * d % mod;
	segment_tree[id << 1].tip2 = segment_tree[id << 1].tip2 * d % mod;
	d = t.tip2;
	segment_tree[id << 1].three = (segment_tree[id << 1].three + 3 * segment_tree[id << 1].two % mod * d % mod) % mod;
	segment_tree[id << 1].three = (segment_tree[id << 1].three + 3 * segment_tree[id << 1].one % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1].three = (segment_tree[id << 1].three + (mid - l + 1) % mod * d % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1].two = (segment_tree[id << 1].two + 2 * segment_tree[id << 1].one % mod * d % mod) % mod;
	segment_tree[id << 1].two = (segment_tree[id << 1].two + (mid - l + 1) % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1].one = (segment_tree[id << 1].one + (mid - l + 1) % mod * d % mod) % mod;
	segment_tree[id << 1].tip2 = (segment_tree[id << 1].tip2 + d) % mod;

	d = t.tip1;
	segment_tree[id << 1 ^ 1].one = segment_tree[id << 1 ^ 1].one * d % mod;
	segment_tree[id << 1 ^ 1].two = segment_tree[id << 1 ^ 1].two * d % mod * d % mod;
	segment_tree[id << 1 ^ 1].three = segment_tree[id << 1 ^ 1].three * d % mod * d % mod * d % mod;
	segment_tree[id << 1 ^ 1].tip1 = segment_tree[id << 1 ^ 1].tip1 * d % mod;
	segment_tree[id << 1 ^ 1].tip2 = segment_tree[id << 1 ^ 1].tip2 * d % mod;
	d = t.tip2;
	segment_tree[id << 1 ^ 1].three = (segment_tree[id << 1 ^ 1].three + 3 * segment_tree[id << 1 ^ 1].two % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].three = (segment_tree[id << 1 ^ 1].three + 3 * segment_tree[id << 1 ^ 1].one % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].three = (segment_tree[id << 1 ^ 1].three + (r - mid) % mod * d % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].two = (segment_tree[id << 1 ^ 1].two + 2 * segment_tree[id << 1 ^ 1].one % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].two = (segment_tree[id << 1 ^ 1].two + (r - mid) % mod * d % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].one = (segment_tree[id << 1 ^ 1].one + (r - mid) % mod * d % mod) % mod;
	segment_tree[id << 1 ^ 1].tip2 = (segment_tree[id << 1 ^ 1].tip2 + d) % mod;
	tipclear(id);
//	printf("STATES AFTER TAGDOWN\n");
//	printf("ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
//	printf("LC = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id << 1, l, mid, segment_tree[id << 1].one, segment_tree[id << 1].two, segment_tree[id << 1].three, segment_tree[id << 1].tip1, segment_tree[id << 1].tip2, segment_tree[id << 1].istip3, segment_tree[id << 1].tip3);
//	printf("RC = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id << 1 ^ 1, mid + 1, r, segment_tree[id << 1 ^ 1].one, segment_tree[id << 1 ^ 1].two, segment_tree[id << 1 ^ 1].three, segment_tree[id << 1 ^ 1].tip1, segment_tree[id << 1 ^ 1].tip2, segment_tree[id << 1 ^ 1].istip3, segment_tree[id << 1 ^ 1].tip3);
//	printf("END FUNCTION TAGDOWN\n");
	return;
}
void collect(LL id, LL l, LL r) {
	if(l == r) return;
	segment_tree[id].one = (segment_tree[id << 1].one + segment_tree[id << 1 ^ 1].one) % mod;
	segment_tree[id].two = (segment_tree[id << 1].two + segment_tree[id << 1 ^ 1].two) % mod;
	segment_tree[id].three = (segment_tree[id << 1].three + segment_tree[id << 1 ^ 1].three) % mod;
//	printf("COLLECTION : ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//		id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
	return;
}
void build(LL id, LL l, LL r) {
	tipclear(id);
	if(l == r) return;
	LL mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 ^ 1, mid + 1, r);
	return;
}
void add(LL id, LL l, LL r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		segment_tree[id].three = (segment_tree[id].three + 3 * segment_tree[id].two % mod * d % mod) % mod;
		segment_tree[id].three = (segment_tree[id].three + 3 * segment_tree[id].one % mod * d % mod * d % mod) % mod;
		segment_tree[id].three = (segment_tree[id].three + (r - l + 1) % mod * d % mod * d % mod * d % mod) % mod;
		segment_tree[id].two = (segment_tree[id].two + 2 * segment_tree[id].one % mod * d % mod) % mod;
		segment_tree[id].two = (segment_tree[id].two + (r - l + 1) % mod * d % mod * d % mod) % mod;
		segment_tree[id].one = (segment_tree[id].one + (r - l + 1) % mod * d % mod) % mod;
		segment_tree[id].tip2 = d;
//		printf("ADD : ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//			id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
		return;
	}
	LL mid = l + r >> 1;
	if(x <= mid) add(id << 1, l, mid);
	if(y > mid) add(id << 1 ^ 1, mid + 1, r);
	collect(id, l, r);
	return;
}
void multiply(LL id, LL l, LL r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		segment_tree[id].three = segment_tree[id].three * d % mod * d % mod * d % mod;
		segment_tree[id].two = segment_tree[id].two * d % mod * d % mod;
		segment_tree[id].one = segment_tree[id].one * d % mod;
		segment_tree[id].tip1 = d;
//		printf("MULTIPLY : ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//			id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
		return;
	}
	LL mid = l + r >> 1;
	if(x <= mid) multiply(id << 1, l, mid);
	if(y > mid) multiply(id << 1 ^ 1, mid + 1, r);
	collect(id, l, r);
	return;
}
void change(LL id, LL l, LL r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		tipclear(id);
		segment_tree[id].one = (r - l + 1) % mod * d % mod;
		segment_tree[id].two = segment_tree[id].one * d % mod;
		segment_tree[id].three = segment_tree[id].two * d % mod;
		segment_tree[id].istip3 = 1;
		segment_tree[id].tip3 = d;
//		printf("CHANGE : ID = %4lld l = %4lld r = %4lld one = %4lld two = %4lld three = %4lld tip1 = %4lld tip2 = %4lld istip3 = %4lld tip3 = %4lld\n",
//			id, l, r, segment_tree[id].one, segment_tree[id].two, segment_tree[id].three, segment_tree[id].tip1, segment_tree[id].tip2, segment_tree[id].istip3, segment_tree[id].tip3);	
		return;
	}
	LL mid = l + r >> 1;
	if(x <= mid) change(id << 1, l, mid);
	if(y > mid) change(id << 1 ^ 1, mid + 1, r);
	collect(id, l, r);
	return;
}
LL ask(LL id, LL l, LL r) {
	tagdown(id, l, r);
	if(x <= l && r <= y) {
		if(d == 1) return segment_tree[id].one;
		if(d == 2) return segment_tree[id].two;
		if(d == 3) return segment_tree[id].three;
		return 0;
	}
	LL t1 = 0, t2 = 0;
	LL mid = l + r >> 1;
	if(x <= mid) t1 = ask(id << 1, l, mid);
	if(y > mid) t2 = ask(id << 1 ^ 1, mid + 1, r);
	return (t1 + t2) % mod;
}
int main() {
	scanf("%lld%lld", &n, &m);
	while(!(n == 0 && m == 0)) {
		memset(segment_tree, 0, sizeof(segment_tree));
		build(1, 1, n);
		for(LL i = 1; i <= m; i++) {
			scanf("%lld%lld%lld%lld", &k, &x, &y, &d);
			d %= mod;
			if(k == 1) add(1, 1, n);
			if(k == 2) multiply(1, 1, n);
			if(k == 3) change(1, 1, n);
			if(k == 4) printf("%lld\n", ask(1, 1, n));
		}
		scanf("%lld%lld", &n, &m);
	}
	return 0;
}
