#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000010], l, r, mid;
int check(int x){
	int cnt = 1, la  = 1;
	for(int i = 2; i <= n; i++)
		if(a[i] - a[la] >= x){
			cnt++;
			la = i;
		}
	return (cnt >= m) ? 1 : 0;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	l = 0; r = 1000000000;
	while(l < r){
		mid = (l + r + 1) / 2;
		if(check(mid)) l = mid; else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
