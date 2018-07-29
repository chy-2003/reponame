#include<bits/stdc++.h>
using namespace std;
const int MAXQ = 500010;
int f[MAXQ << 1][22], deep[MAXQ << 1], rec[2], t, q, x, dis, dis1, l;
void add(int t){
	l++;
	deep[l] = deep[t] + 1;
	f[l][0] = t;
	for(int i = 1; i < 22; i++) f[l][i] = f[f[l][i - 1]][i - 1];
	return;
}
int lca(int x, int y){
	if(deep[x] < deep[y]) swap(x, y);
	for(int j = 21; j >= 0; j--)
		if(deep[f[x][j]] >= deep[y]) x = f[x][j];
	if(x == y) return x;
	for(int j = 21; j >= 0; j--)
		if(f[x][j] != f[y][j]) x = f[x][j], y = f[y][j];
	return f[x][0];
}
int getdis(int x, int y){
	int t = lca(x, y);
	return deep[x] + deep[y] - 2 * deep[t];
}
int main(){
	int ans = 2;
	f[1][0] = 0; f[2][0] = 0; f[3][0] = 0;
	deep[1] = 1; deep[2] = 1; deep[3] = 1;
	l = 3;
	rec[0] = 1; rec[1] = 2;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		scanf("%d", &t); t--;
		dis = getdis(t, rec[0]);
		if(dis >= ans) x = 1;
		dis1 = getdis(t, rec[1]);
		if(dis1 > dis){
			dis = dis1;
			x = 0;
		}
		if(dis >= ans){
			ans = dis + 1;
			rec[x] = l + 1;		
		}
		printf("%d\n", ans);
		add(t); add(t);
	}
	return 0;
}
