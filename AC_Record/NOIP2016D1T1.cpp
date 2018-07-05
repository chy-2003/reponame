#include<bits/stdc++.h>
using namespace std;
int n, m, a[100010], x, y;
string b[100010];
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < n; i++) if(a[i] == 0) a[i] = -1;
	int ans = 0;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		if(x == 0) x = -1;
		ans = ans - y * x * a[ans];
		ans = ans % n;
		if(ans < 0) ans += n;
	} 
	cout << b[ans];
	return 0;
}