#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x, id;
};
int n, ans[100010], rec[100010], t1, t2;
Node a[100010];
bool cmp(Node x, Node y){ return x.x < y.x; }
int upper(int x, int y){
	//printf("%d %d %d %d ", x, y, rec[x], rec[y]);
	if(rec[x] > rec[y]) return (ans[y] + 1);
	 else
	return 1;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i].x);
	for(int i = 1; i <= n; i++) rec[i] = a[i].x;
//	for(int i = 1; i <= n; i++) printf("%d ", rec[i]);
//	printf("\n");
	for(int i = 1; i <= n; i++) a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	rec[0] = 10010;
	rec[n + 1] = 10010;
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++){
		t1 = upper(a[i].id, a[i].id - 1); //printf("%d\n", t1);
		t2 = upper(a[i].id, a[i].id + 1); //printf("%d\n", t2);
		ans[a[i].id] = max(t1, t2);
	//	for(int j = 1; j <= n; j++) printf("%d ", ans[j]); printf("\n");
	}
	//printf("\n");
	long long cnt = 0;
	for(int i = 1; i <= n; i++) cnt += ans[i];
	printf("%lld\n", cnt);
	return 0;
}
