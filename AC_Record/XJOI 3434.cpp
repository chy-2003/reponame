//XJOI 3434
#include <bits/stdc++.h>
using namespace std;
long long n, ans, e[1000010], t;
int main(){
	cin >> n;
	for(int i = 2; i <= n; i++) e[i] = 1;
	e[1] = 0;
	for(int i = 2; i <= n; i++){
		if(e[i] != 1) continue;
		e[i] = i - 1;
		for(int j = i + i; j <= n; j += i){
			e[j] *= (i - 1);
			t = j / i;
			while(t % i == 0){
				t /= i;
				e[j] *= i;
			}
		}
	}
//	for(int i = 1; i <= n; i++) cout << i << " " << e[i] << endl;
	ans = 1;
	for(int i = 3; i <= n; i++) ans += e[i];
	cout << ans;
	return 0;
}