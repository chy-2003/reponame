#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
const int INF = 1000000000;
int n, m, a[MAXN];
struct Node {
	int Gss, Lgss, Rgss, Sum;
	Node(int Gss_ = 0, int Lgss_ = 0, int Rgss_ = 0, int Sum_ = 0) {
		Gss = Gss_; Lgss = Lgss_; Rgss = Rgss_; Sum = Sum_; return;
	}
};
Node segment_tree[MAXN << 2];
int x, y;
Node merge(Node x, Node y) {
	return Node(max(max(x.Gss, y.Gss), x.Rgss + y.Lgss), max(x.Lgss, x.Sum + y.Lgss), max(x.Rgss + y.Sum, y.Rgss), x.Sum + y.Sum);
}
Node build(int id, int l, int r) {
	if(l == r) {
		segment_tree[id] = Node(a[l], a[l], a[l], a[l]);
		return segment_tree[id];
	}
	int mid = l + r >> 1;
	segment_tree[id] = merge(build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r));
	return segment_tree[id];
}
Node ask(int id, int l, int r) {
	if(x <= l && r <= y) return segment_tree[id];
	int mid = l + r >> 1;
	Node t1 = Node(-INF, -INF, -INF, 0), t2 = Node(-INF, -INF, -INF, 0);
	if(x <= mid) t1 = ask(id << 1, l, mid);
	if(y > mid) t2 = ask(id << 1 | 1, mid + 1, r);
	return merge(t1, t2);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	segment_tree[1] = build(1, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", ask(1, 1, n).Gss);
	}
	return 0;
}
