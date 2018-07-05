//XJOI 3595
#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1;
int main(){
	cin >> n;
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			ans *= (i - 1);
			n /= i;
			while(n % i == 0){
				ans *= i;
				n /= i;
			}
		}
	}
	if(n != 1) ans *= (n - 1);
	cout << ans;
	return 0;
}