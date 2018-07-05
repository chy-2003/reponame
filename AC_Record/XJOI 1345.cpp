//XJOI 1345
#include <bits/stdc++.h>
using namespace std;
int a[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, x, y, b[370], l, t;
double db;
int main(){
	for(int i = 1; i <= 12; i++) a[i] += a[i - 1];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &x, &y);
		t = a[x - 1] + y;
		l++;
		b[l] = t;
	}
	sort(b + 1, b + l + 1);
	b[0] = 0;
	l++;
	b[l] = 367;
	t = 0;
	for(int i = 1; i <= l; i++) t = max(t, b[i] - b[i - 1] - 1);
//	printf("%d\n", t);
	db = (double)((double)(t / 366.0) * 86400.0);
	printf("%.0lf", db);
	return 0;
}