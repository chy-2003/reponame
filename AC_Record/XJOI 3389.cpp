//XJOI 3389
#include <bits/stdc++.h>
using namespace std;
long long n, ans;
long long gcd(long long x, long long y){
	long long t = x % y;
	while(t){
		x = y; y = t; t = x % y;
	}
	return y;
}
int main(){
	cin >> n;
	ans = gcd(n + 1, 4 * n);
	ans = (4 * n) / ans;
	cout << ans + 1;
	return 0;
}