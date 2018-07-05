#include<bits/stdc++.h>
using namespace std;
long long s, t, n, m, a[1010], b[1010], c[1010], rec[1010][1010], dis[1010], cnt, bb, rec2[1010];

void p(long long x){
    if(x == 0) return;
    p(rec2[x]);
    printf("%lld ", x);
    return;
}

long long cmp(long long t){
	if(dis[a[t]] == -1000000000000000001) return 0;
	if(dis[b[t]] == -1000000000000000001) return 1;
	if((dis[a[t]] + c[t] < dis[b[t]]) || ((dis[a[t]] + c[t] == dis[b[t]]) && rec2[b[t]] > a[t])) return 1;
	return 0;
}

int main(){
	scanf("%lld%lld", &s, &t);
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= m; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	for(long long i = 1; i <= n; i++) dis[i] = -1000000000000000001;
	dis[s] = 0;
	rec2[s] = 0;
	for(long long i = 1; i <= n + 1; i++){
		bb = 0;
		for(long long j = 1; j <= m; j++)
			if(cmp(j)){
				bb = 1;
				dis[b[j]] = dis[a[j]] + c[j];
//				printf("%lld %lld\n", b[j], dis[b[j]]);
				rec2[b[j]] = a[j];
			}
		if(bb == 1) cnt++; else break;
	}
	if(cnt > n) printf("You show me the wrong map!"); else{
		printf("%lld\n", dis[t]);
		p(t);
	}
	return 0;
}