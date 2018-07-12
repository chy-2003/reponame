#include<bits/stdc++.h>
using namespace std;
struct Node{
	string s;
	int num;
};
struct Node2{
	string s;
	int t, pos;
};
bool cmp(Node2 x, Node2 y){
	return x.s < y.s || x.s == y.s && x.pos < y.pos;
}
Node a[10010];
Node2 b[10010];
int n, k;
int find(string s){
	int l = 1, r = k, mid;
	while(l < r){
		mid = (l + r + 1) / 2;
		if(b[mid].s <= s) l = mid; else r = mid - 1;
	}
	return l;
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i].s >> a[i].num;
	for(int i = 1; i <= k; i++) cin >> b[i].s >> b[i].t;
	for(int i = 1; i <= k; i++) b[i].pos = i;
	sort(b + 1, b + k + 1, cmp);
	b[k + 1].s = "";
//	for(int i = 1; i <= k; i++) if(b[i].s == b[i - 1].s) b[i].t += b[i - 1].t;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int t = find(a[i].s);
		if(b[t].s != a[i].s){
			printf("Unknow\n");
			return 0;
		}
		while(b[t + 1].s == b[t].s) t++;
		ans += (long long)a[i].num * b[t].t;
	}
	printf("%lld\n", ans);
	return 0;
}
