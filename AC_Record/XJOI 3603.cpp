#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a, b;
};
int n;
Node a[5010];
bool cmp(Node x, Node y){
	return x.a < y.a || x.a == y.a && x.b < y.b;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i].b >= ans) ans = max(ans, a[i].b); else ans = max(ans, a[i].a);
	}
	printf("%d", ans);
	return 0;
}
