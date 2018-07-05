//XJOI 3598
#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
long long n, k, a[1010][1010];
int main(){
	scanf("%lld%lld", &n, &k);
	a[1][1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i; j++)
			a[i][j] = ((a[i - 1][j] * j) % M + a[i - 1][j - 1]) % M;
	printf("%lld", a[n][k]);
	return 0;
}