#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x, id;
	Node(int x_ = 0, int id_ = 0) {x = x_; id = id_;}
};
const int MAXN = 200010;
int n, x, ans[MAXN], tree[MAXN];
Node a[MAXN];

bool cmp(Node x, Node y){
	return x.x < y.x || x.x == y.x && x.id < y.id;
}

int lowbit(int x){ return x & (-x); }

int ask(int x){
	int t = 0;
//	printf("%d \n", x);
	while(x){
//		printf("%d %d\n", x, tree[x]);
		t += tree[x];
		x -= lowbit(x);
	}
//	printf("t = %d\n", t);
	return t;
}

void add(int x){
	if(x == 0) return;
	while(x < n){
		tree[x]++;
		x += lowbit(x);
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		a[i] = Node(x, i);
	}
	sort(a, a + n, cmp);
//	for(int i = 0; i <= n; i++) printf("%d %d\n", a[i].x, a[i].id);
	memset(ans, 0, sizeof(ans));
//	printf("*\n");
	for(int i = 0; i < n; i++){
//		printf("i = %d  id = %d\n", i, a[i].id);
		for(int k = 1; k * a[i].id + 1 < n && k < n; k++){
//			printf("k = %d\n", k);
			ans[k] += ask(min(k * a[i].id + k, n - 1)) - ask(k * a[i].id);
//			printf("k = %d   ansk = %d\n", k, ans[k]);
		}
		add(a[i].id);
//		printf("*\n");
	}
	for(int i = 1; i < n; i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}
