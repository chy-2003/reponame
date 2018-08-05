#include <bits/stdc++.h>
using namespace std;
const double INF = 1.0 / 0.0;
int n;
double ans;
struct Node {
	double x, y;
};
Node a[100010];
bool cmp(Node x, Node y) { return x.x < y.x; }
double x, y;
double sqr(double x) { return x * x; }
int main() {
	scanf("%d", &n);
	while(n) {
		for(int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x, &y);
			a[i].x = cos(1.142857) * x - sin(1.142857) * y;
			a[i].y = sin(1.142857) * x + cos(1.142857) * y;
		}
		ans = INF;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 2; j++) {
				if(j + i > n) break;
				ans = min(ans, sqrt(sqr(a[i].x - a[i + j].x) + sqr(a[i].y - a[i + j].y)));
			}
		printf("%.2lf\n", ans / 2);
		scanf("%d", &n);
	}
	return 0;
}
