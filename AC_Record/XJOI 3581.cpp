#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
int n, k, w[MAXN], v[MAXN];
double l, r, t[MAXN], mid, sum;
bool cmp(double x, double y){
	return x > y;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	l = 0; r = 1000010;
	while(r - l > 0.0001){
		mid = (l + r) / 2;
		for(int i = 1; i <= n; i++) t[i] = v[i] - w[i] * mid;
		sum = 0;
		sort(t + 1, t + n + 1, cmp);
		for(int i = 1; i <= k; i++) sum += t[i];
		if(sum > 0) l = mid; else r = mid;
	}
	printf("%.2lf", r);
	return 0;
}
