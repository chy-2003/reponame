#include<bits/stdc++.h>
using namespace std;
int pnum, p[10010], vis[100010], t;
int n, a[100010], tag[100010], rec[10010], l, fact[20];
int main(){
	pnum = 0;
	for(int i = 2; i <= 100000; i++){
		if(vis[i]) continue;
		pnum++; p[pnum] = i; tag[i] = pnum;
		for(int j = i + i; j <= 100000; j += i)
			if(!vis[j]) vis[j] = 1;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		t = a[i];
		l = 0;
		for(int j = 1; p[j] * p[j] <= t && j <= pnum; j++)
			if(t % p[j] == 0){
				l++; fact[l] = j;
				while(t % p[j] == 0) t /= p[j];
			}
		if(t > 1){
			l++;
			fact[l] = tag[t];
		}
		t = 1;
		for(int j = 1; j <= l; j++) t = max(t, rec[fact[j]] + 1);
		for(int j = 1; j <= l; j++) rec[fact[j]] = t;
	}
	t = 1;
	for(int i = 1; i <= pnum; i++) t = max(t, rec[i]);
	printf("%d\n", t);
	return 0;
}