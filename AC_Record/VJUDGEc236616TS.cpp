#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1510;
int n, x, y;
int lp = 0, f[MAXN], nex[MAXN << 1], lin[MAXN << 1];
void add(int x, int y){ nex[++lp] = f[x]; lin[lp] = y; f[x] = lp; return; }


int X = 0, Y = 0;
struct Point{
	int x, y, pos;
	Point(int x_ = 0, int y_ = 0, int pos_ = 0){ x = x_; y = y_; pos = pos_; }
	bool operator < (const Point cmp)const {
		int x1, y1, x2, y2;
		x1 = x - X; y1 = y - Y;
		x2 = cmp.x - X; y2 = cmp.y - Y;
		return (long long)y1 * x2 < (long long)y2 * x1;
	}
};
Point a[MAXN];


int ans[MAXN], size[MAXN];




void ltree(int father, int pos){
	int t = f[pos];
	size[pos] = 0;
	while(t){
		if(lin[t] != father){
			ltree(pos, lin[t]);
			size[pos] += size[lin[t]];
		}
		t = nex[t];
	}
	size[pos]++;
	return;
}


void dfs(int father, int pos, int l, int r){
	int tt = l;
	for(int i = l + 1; i <= r; i++)
		if(a[i].y < a[tt].y || a[i].y == a[tt].y && a[i].x < a[tt].x)
			tt = i;
	swap(a[tt], a[l]);
	ans[a[l].pos] = pos;
	X = a[l].x;
	Y = a[l].y;
	sort(a + l + 1, a + r + 1);
	l++;
	int t = f[pos];
	while(t){
		if(lin[t] != father){
			dfs(pos, lin[t], l, l + size[lin[t]] - 1);
			l += size[lin[t]];
		}
		t = nex[t];
	}
	return;
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &x, &y);
		a[i] = Point(x, y, i);
	}
	ltree(1, 1);
	dfs(1, 1, 1, n);
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}
