#include<bits/stdc++.h>
using namespace std;
int n, m, dis[2010], vis[2010], x, y, z;
int l, r, q[4000010], cnt[2010], inqueue[2010];
int lp, f[2010], nxt[6010], lin[6010], val[6010];
void add(int x, int y, int z){nxt[++lp] = f[x]; lin[lp] = y; val[lp] = z; f[x] = lp; return;}
void work(){
	scanf("%d%d", &n, &m);
	lp = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		if(z >= 0) add(y, x, z);
	}
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	memset(cnt, 0, sizeof(cnt));
	cnt[1] = 1;
	memset(inqueue, 0, sizeof(inqueue));
	l = 0; r = 1; q[1] = 1;
	inqueue[1] = 1;
	while(l < r){
		l++;
		inqueue[q[l]] = 0;
		for(int t = f[q[l]]; t; t = nxt[t])
			if(vis[lin[t]] == 0 || dis[lin[t]] > dis[q[l]] + val[t]){
				vis[lin[t]] = 1;
				dis[lin[t]] = dis[q[l]] + val[t];
				cnt[lin[t]]++;
				if(!inqueue[lin[t]]){
					if(cnt[lin[t]] >= n){
						printf("YE5\n");
						return;
					}
					r++; q[r] = lin[t];
					inqueue[lin[t]] = 1;
				}
			}
	}
	printf("N0\n");
	return;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) work();
	return 0;
}

