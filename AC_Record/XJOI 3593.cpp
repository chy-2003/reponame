//XJOI 3593
#include <bits/stdc++.h>
using namespace std;
long long x, y, a, b;
long long gcd(long long x, long long y){
	long long t = x % y;
	while(t){
		x = y; y = t; t = x % y;
	}
	return y;
}
void exgcd(long long x, long long y, long long &a, long long &b){
	if(y == 0){
		a = 1; b = 0;
		return;
	}
	exgcd(y, x % y, b, a);
	b -= (x / y) * a;
	return;
}
int main(){
	scanf("%lld%lld", &x, &y);
	if(gcd(x, y) != 1){
		printf("-1");
		return 0;
	}
	exgcd(x, y, a, b);
//	printf("%lld\n", a);
	a %= y;
	if(a < 0) a += y;
	printf("%lld", a);
	return 0;
}