#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010, MAXM = 1010;
struct Edge {
	int x, y, z, color;
	Edge(int x_ = 0, int y_ = 0, int z_ = 0, int color_ = 0) { x = x_; y = y_; z = z_; color = color_; return; }
};
Edge edge[MAXM << 1];
int val1, val2, father1[MAXN], father2[MAXN], cnt1, cnt2, used1[MAXM], used2[MAXM];
int x, y, z;
char ch;
int n, m;
void init() {
	val1 = val2 = 0;
	cnt1 = cnt2 = 0;
	memset(used1, 0, sizeof(used1)); memset(used2, 0, sizeof(used2));
	memset(edge, 0, sizeof(edge));
	for(int i = 1; i <= n; i++) father1[i] = i, father2[i] = i;
	return;
}
int get_father1(int x) {
	if(father1[x] == x) return x;
	father1[x] = get_father1(father1[x]);
	return father1[x];
}
int get_father2(int x) {
	if(father2[x] == x) return x;
	father2[x] = get_father2(father2[x]);
	return father2[x];
}
void add_tree_edge1() {
	for(int i = 1; i <= m; i++) {
		if(edge[i].color == 3) continue; 
		if(used1[i]) continue;
		int x = get_father1(edge[i].x);
		int y = get_father1(edge[i].y);
		if(x == y) continue;
		used1[i] = 1;
		val1 += edge[i].z;
		father1[y] = x;
		cnt1++;
		break;
	}
	return;
}
void add_tree_edge2() {
	for(int i = 1; i <= m; i++) {
		if(edge[i].color == 1) continue; 
		if(used2[i]) continue;
		int x = get_father2(edge[i].x);
		int y = get_father2(edge[i].y);
		if(x == y) continue;
		used2[i] = 1;
		val2 += edge[i].z;
		father2[y] = x;
		cnt2++;
		break;
	}
	return;
}
void choosemin1() {
	for(int i = 1; i <= m; i++) {
		if(used1[i]) continue;
		used1[i] = 1;
		val1 += edge[i].z;
		break;
	}
	return;
}
void choosemin2() {
	for(int i = 1; i <= m; i++) {
		if(used2[i]) continue;
		used2[i] = 1;
		val2 += edge[i].z;
		break;
	}
	return;
}
void add_edge1() {
	if(cnt1 < n - 1) add_tree_edge1(); else choosemin1();
	return;
}
void add_edge2() {
	if(cnt2 < n - 1) add_tree_edge2(); else choosemin2();
	return;
}
int get_ans() {
	if(cnt1 < n - 1 && cnt2 < n - 1) return -1;
	if(cnt1 < n - 1) return val2;
	if(cnt2 < n - 1) return val1;
	return min(val1, val2);
}
bool cmp(Edge x, Edge y) { return x.z < y.z; }
int getnum(char ch) {
	if(ch == 'R') return 1;
	if(ch == 'G') return 2;
	if(ch == 'B') return 3;
}
void work() {
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		ch = getchar(); while(ch != 'R' && ch != 'G' && ch != 'B') ch = getchar();
		edge[i] = Edge(x, y, z, getnum(ch));
	}
	sort(edge + 1, edge + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		add_edge1();
		add_edge2();
		printf("%d\n", get_ans());
	}
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) printf("Case #%d:\n", i), work();
	return 0;
}
