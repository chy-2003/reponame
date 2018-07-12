#include<bits/stdc++.h>
using namespace std;
long long n, cost[100010], f[100010][2], len;
string st[100010], st1[100010];
int main(){
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> cost[i];
	for(long long i = 1; i <= n; i++) cin >> st[i];
	for(long long i = 1; i <= n; i++){
		st1[i] = st[i];
		len = st1[i].size();
		for(long long j = 0; j + j < len - 1; j++) swap(st1[i][j], st1[i][len - j - 1]);
	}
	f[1][0] = 0; f[1][1] = cost[1];
	for(int i = 2; i <= n; i++){
		f[i][0] = 1000000000000000;
		f[i][1] = 1000000000000000;
		if(st[i] >= st[i - 1]) f[i][0] = min(f[i][0], f[i - 1][0]);
		if(st[i] >= st1[i - 1]) f[i][0] = min(f[i][0], f[i - 1][1]);
		if(st1[i] >= st[i - 1]) f[i][1] = min(f[i][1], f[i - 1][0] + cost[i]);
		if(st1[i] >= st1[i - 1]) f[i][1] = min(f[i][1], f[i -1 ][1] + cost[i]);
	}
//	for(int i = 1; i <= n; i++) cout << st[i] << " " << st1[i] << endl;
//	for(int i = 1; i <= n; i++) cout << f[i][0] << " " << f[i][1] << endl;
	long long ans = 1000000000000000;
	ans = min(f[n][0], f[n][1]);
	if(ans == 1000000000000000) printf("-1\n"); else printf("%lld\n", ans);
	return 0;
}
