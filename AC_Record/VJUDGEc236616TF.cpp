#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct Matrices{
	LL a[2][2];
	Matrices (LL a1, LL a2, LL a3, LL a4) {a[0][0] = a1; a[0][1] = a2; a[1][0] = a3; a[1][1] = a4;}
};
LL n, k, l, m, num_0, num_1, cnt1, cnt2, ans;
Matrices d = Matrices(1, 1, 1, 0), one = Matrices(1, 0, 0, 1);

Matrices muilti(Matrices a, Matrices b){
	Matrices t = Matrices(0, 0, 0, 0);
	t.a[0][0] = ((a.a[0][0] * b.a[0][0]) % m + (a.a[0][1] * b.a[1][0]) % m) % m;
	t.a[0][1] = ((a.a[0][0] * b.a[0][1]) % m + (a.a[0][1] * b.a[1][1]) % m) % m;
	t.a[1][0] = ((a.a[1][0] * b.a[0][0]) % m + (a.a[1][1] * b.a[1][0]) % m) % m;
	t.a[1][1] = ((a.a[1][0] * b.a[0][1]) % m + (a.a[1][1] * b.a[1][1]) % m) % m;
	return t;
}
Matrices Mpow(LL x){
	if(x == 0) return one;
	Matrices t = Mpow(x / 2);
	t = muilti(t, t);
	if(x & 1 == 1) t = muilti(d, t);
	return t;
}
LL get_cnt(LL pow){
	Matrices t = Mpow(pow);
	return (((t.a[0][0] + t.a[0][1]) % m) + (t.a[1][0] + t.a[1][1]) % m) % m;
}

LL expow(LL x){
	if(x == 0) return 1;
	LL t = expow(x / 2);
	t = (t * t) % m;
	if(x & 1 == 1) t = (t << 1) % m;
	return t;
}


int main(){
	cin >> n >> k >> l >> m;
	if(log((double)k) / log(2.0) >= (double) l){
		printf("0");
		return 0;
	}
	while(k){
		if(k & 1) num_1++;
		k >>= 1;
	}
	num_0 = l - num_1;
	cnt1 = get_cnt(n - 1);
	cnt2 = expow(n) - cnt1; 
	if(cnt2 < 0) cnt2 += m;
	ans = 1 % m;
	while(num_0){
		ans = (ans * cnt1) % m;
		num_0--;
	}
	while(num_1){
		ans = (ans * cnt2) % m;
		num_1--;
	}
	cout << ans;
	return 0;
}
