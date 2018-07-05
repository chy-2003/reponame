#include <bits/stdc++.h>
using namespace std;

int n, h, fla[1010][1010];
long long x[1010], y[1010], z[1010], R;
int l, q[1010], ca[1010], r;

void work();
	bool cmp(int xx, int yy);
		long long sqr(long long t);

int main(){
	int t;
	scanf("%d", &t);
	while(t){
		work();
		t--;
	}
	return 0;
}

void work(){
	scanf("%d%d%lld", &n, &h, &R);
	for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
	memset(fla, 0, sizeof(fla));
	for(int i = 1; i <= n; i++){
		if(z[i] <= R){ fla[0][i] = 1; fla[i][0] = 1; }
		if(z[i] + R >= h){ fla[i][n + 1] = 1; fla[n + 1][i] = 1; }
	}
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			if(cmp(i, j)){ fla[i][j] = 1; fla[j][i] = 1; }
//	for(int i = 0; i <= n + 1; i++){
//		for(int j = 0; j <= n + 1; j++)
//			printf("%d", (fla[i][j] == 1) ? 1 : 0);
//		printf("\n");
//	}
	memset(ca, 0, sizeof(ca));
	l = 0; r = 1; q[1] = 0;
	ca[0] = 1;
	while(l < r){
		l++;
		for(int i = 0; i <= n + 1; i++)
			if(ca[i] == 0 && fla[q[l]][i] == 1){
				r++;
				q[r] = i;
//				printf("%d\n", i);
				ca[i] = 1;
			}
	}
	if(ca[n + 1] == 1) printf("Yes\n"); else printf("No\n");
	return;
}

bool cmp(int xx, int yy){ return (sqr(x[xx] - x[yy]) + sqr(y[xx] - y[yy]) + sqr(z[xx] - z[yy])) <= sqr(2 * R); }

long long sqr(long long t){ return t * t; }