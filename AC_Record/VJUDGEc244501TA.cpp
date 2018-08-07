#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200010, INF = 2147483647;
int segment_tree[MAXN << 2];
int n, m;
int a[MAXN];
char ch;
int x, y;
void build(int id, int l, int r) {
	if(l == r) {
		segment_tree[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid + 1, r);
	segment_tree[id] = max(segment_tree[id << 1], segment_tree[(id << 1) + 1]);
	return;
}
int ask(int id, int l, int r) {
	if(x <= l && r <= y) return segment_tree[id];
	int mid = (l + r) >> 1;
	int t1 = -INF, t2 = -INF;
	if(x <= mid) t1 = ask(id << 1, l, mid);
	if(y > mid) t2 = ask((id << 1) + 1, mid + 1, r);
	return max(t1, t2);
}
void change(int id, int l, int r) {
	if(l == r) {
		segment_tree[id] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) change(id << 1, l, mid);
	if(x > mid) change((id << 1) + 1, mid + 1, r);
	segment_tree[id] = max(segment_tree[id << 1], segment_tree[(id << 1) + 1]);
	return;
}
int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		memset(segment_tree, 0, sizeof(segment_tree));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		build(1, 1, n);
		for(int i = 1; i <= m; i++) {
			ch = getchar();
			while(ch != 'Q' && ch != 'U') ch = getchar();
			scanf("%d%d", &x, &y);
			if(ch == 'Q') printf("%d\n", ask(1, 1, n)); else change(1, 1, n);
		}
	}
	return 0;
}
