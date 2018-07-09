#include<bits/stdc++.h>
using namespace std;
int n, m, a[10][10], rec[10], ans;
void work(int s, int id){
	if(id > n){
		ans = max(ans, s);
		return;
	}
	work(s, id + 1);
	for(int i = 1; i <= m; i++){
		if(rec[i] == 2) continue;
		rec[i]++;
		work(s + a[id][i], id + 1);
		rec[i]--;
	}
	for(int i = 1; i < m; i++)
		for(int j = i + 1; j <= m; j++){
			if(rec[i] == 2 || rec[j] == 2) continue;
			rec[i]++; rec[j]++;
			work(s + a[id][i] + a[id][j], id + 1);
			rec[i]--; rec[j]--;
		}
	return;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	memset(rec, 0, sizeof(rec));
	ans = 0;
	work(0, 1);
	printf("%d\n", ans);
	return 0;
}
