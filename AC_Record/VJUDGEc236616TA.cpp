#include<bits/stdc++.h>
using namespace std;
map<int, int> ct;
int n, a[10010], f[10010], ans[10010], cnt;
int l = 0, b[10010], p[10010];
int main(){
	memset(b, 0, sizeof(b));
	memset(ans, 0, sizeof(ans));
	memset(p, 0, sizeof(p));
	memset(f, 0, sizeof(f));
	memset(a, 0, sizeof(a));
	n = 0;
	cnt = 0;
	l = 0;
	for(int i = 2; i < 10010; i++){
		if(b[i] == 0){
			l++; p[l] = i;
		} else continue;
		for(int j = i + i; j < 10010; j += i)
			if(b[j] == 0) b[j] = 1;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; (j <= l) && ((p[j] * p[j]) <= abs(a[i])); j++){
			while(a[i] != 0 && a[i] % (p[j] * p[j]) == 0) a[i] /= (p[j] * p[j]);
			if(a[i] == 0 || a[i] == 1 || a[i] == -1) break;
		}
	for(int i = 1; i <= n; i++){
		f[i] = ct[a[i]];
		ct[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		cnt = 0;
		for(int j = i; j <= n; j++){
			if(a[j] && f[j] < i) cnt++;
			ans[max(1, cnt)]++;
		}
	}
	for(int i = 1; i <= n; i++) 
		if(i == 1) printf("%d", ans[i]); else printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
