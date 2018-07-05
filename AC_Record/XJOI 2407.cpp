//XJOI 2407
#include <bits/stdc++.h>
using namespace std;
long long x, y, n, m, l, t;
void power(long long x, long long y, long long &a, long long &b){
	if(y == 0){
		a = 1; b = 0;
		return;
	}
	power(y, x % y, b, a);
	b -= (x / y) * a;
//	cout << x << " " << y << " " << a << " " << b << endl;
	return;
}
int gcd(int x, int y){
	int n = x % y;
	while(n){
		x = y; y = n; n = x % y;
	}
	return y;
}
int main(){
	cin >> x >> y >> m >> n >> l;
	long long b, c, k;
	if((y - x) % gcd(m - n, l) != 0){
		printf("Impossible");
		return 0;
	}
	t = (m - n) / gcd(abs(m - n), l);
	l = l / gcd(abs(m - n), l);
	power(abs(m - n), l, b, c);
	if(b < 0) b += l;
	if(t < 0) b = -b;
//	cout << b << endl;
	k = ((y - x) / gcd(abs(m - n), l)) * b;
	k %= l;
	if(k < 0) k += l;
	cout << k;
	return 0;
}