//XJOI 3415
#include <bits/stdc++.h>
using namespace std;
long long n, ans, t;
int main(){
	scanf("%lld", &n);
	for(long long i = 2; i * i <= n; i++){
		ans += ((n / i) - 1) * i;
		if(n / i != i)
		ans += (i - 1) * (n / (i + 1) + n / i + 1) * (n / i - n / (i + 1)) / 2;
	}
	printf("%lld", ans);
	return 0;
}