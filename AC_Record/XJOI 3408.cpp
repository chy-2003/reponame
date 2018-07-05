//XJOI 3408
#include <bits/stdc++.h>
using namespace std;
long long n, a[100010], ans;
struct Node{
	long long num, sum;
};
Node t1, t2;
Node tre[400010];
void add(int t, int i, int l, int r){
	tre[i].num++;
	tre[i].sum += t;
	if(l == r) return;
	if(t <= (l + r) >> 1) add(t, i << 1, l, (l + r) >> 1);
	if(t >= ((l + r) >> 1) + 1) add(t, (i << 1) + 1, ((l + r) >> 1) + 1, r);
	return;
}
Node ask(int ll, int rr, int i, int l, int r){
	if(ll <= l && r <= rr) return tre[i];
	Node t1; t1.num = 0; t1.sum = 0;
	Node t2; t2.num = 0; t2.sum = 0;
	if(ll <= (l + r) >> 1) t1 = ask(ll, rr, i << 1, l, (l + r) >> 1);
	if(rr > (l + r) >> 1) t2 = ask(ll, rr, (i << 1) + 1, ((l + r) >> 1) + 1, r);
	t1.num += t2.num;
	t1.sum += t2.sum;
	return t1;
}
int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = n; i >= 1; i--){
		t1.num = 0; t1.sum = 0;
		t2.num = 0; t2.sum = 0;
		if(1 <= a[i] - 2)
		t1 = ask(1, a[i] - 2, 1, 1, 100000);
		if(a[i] + 2 <= 100000)
		t2 = ask(a[i] + 2, 100000, 1, 1, 100000);
//		cout << "*";
		t1.num += t2.num;
		t1.sum += t2.sum;
		ans += t1.sum - t1.num * a[i];
		add(a[i], 1, 1, 100000);
//		cout << ans;
//		cout << "*";
	}
	cout << ans;
	return 0;
}