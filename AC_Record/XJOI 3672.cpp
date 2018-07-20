#include<cstdio>
int get_int(){
	int t = 0; char ch =getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return t;
}
int ls = 0, st[1000010], x, rec[1000010], ttt[1000010];
int n, m, a[1000010], left[1000010], right[1000010];
inline void spush(int x){st[++ls] = x; return; }
inline int stop(){ return st[ls]; }
inline void spop(){ls--; return; }
void dfs(int x, int t){
	if(x == 0) return;
	if((rec[x] + t) % 2 == 0){
		dfs(left[x], (rec[x] + t) % 2); printf("%d ", a[x]); dfs(right[x], (rec[x] + t) % 2);
	} else{
		dfs(right[x], (rec[x] + t) % 2); printf("%d ", a[x]); dfs(left[x], (rec[x] + t) % 2);
	}
	return;
}
void print_st(){
	for(int i = 1; i <= ls; i++) printf("%d ", st[i]);
	printf("\n");
	return;
}
int main(){
	n = get_int(); m = get_int();
	for(int i = 1; i <= n; i++) a[i] = get_int();
	for(int i = 1; i <= n; i++) ttt[a[i]] = i;
	a[0] = 0;
	spush(0);
	for(int i = 1; i <= n; i++){
		while(a[stop()] > a[i]) spop();
		left[i] = right[stop()];
		right[stop()] = i;
		spush(i);
//		print_st();
	}
//	for(int i = 0; i <= n; i++) printf("%d %d %d\n", i, left[i], right[i]);
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		rec[ttt[x]]++;
		rec[ttt[x]] %= 2;
	}
//	for(int i = 1; i <= n; i++) printf("%d ", rec[i]); printf("\n");
	dfs(right[0], 0);
	return 0;
}
