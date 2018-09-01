#include <bits/stdc++.h>
using namespace std;
double sqr(double x) { return x * x; }
const double eps = 1e-18;
int cmp(double x, double y) {
	if(abs(x - y) <= eps) return 0;
	if(x - y > eps) return 1;
	if(x - y < -eps) return -1;
}
struct Vector {
	double x, y;
	Vector(double x_ = 0, double y_ = 0) { x = x_; y = y_; return; }
	Vector operator + (Vector Other) { return Vector(x + Other.x, y + Other.y); }
	Vector operator - (Vector Other) { return Vector(x - Other.x, y - Other.y); }
	double operator * (Vector Other) { return x * Other.y - y * Other.x; }
	double operator / (Vector Other) { return sqrt(sqr(x - Other.x) + sqr(y - Other.y)); }
};
int n;
Vector a[10010];
bool comperation (Vector x, Vector y) {
	double ans = (x - a[1]) * (y - a[1]);
	return cmp(ans, 0.0) == 1 || cmp(ans, 0.0) == 0 && cmp(x / a[1], y / a[1]) == 1;
}
int top, sta[10010];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
	for(int i = 2; i <= n; i++)
		if(cmp(a[i].x, a[1].x) == -1 || cmp(a[i].x, a[1].x) == 0 && cmp(a[i].y, a[1].y) == -1)
			swap(a[i], a[1]);
	sort(a + 2, a + n + 1, comperation);
	a[n + 1] = a[1];
	top = 0;
	memset(sta, 0, sizeof(sta));
	top = 2;
	sta[1] = 1; sta[2] = 2;
	for(int i = 3; i <= n + 1; i++) {
		while(top > 1 && cmp((a[i] - a[sta[top - 1]]) * (a[sta[top]] - a[sta[top - 1]]), 0.0) == 1) top--;
		sta[++top] = i;
	}
	double ans = 0.0;
	for(int i = 1; i < top; i++) 
		ans += a[sta[i]] / a[sta[i + 1]];
	printf("%.2lf\n", ans);
	return 0;
}
