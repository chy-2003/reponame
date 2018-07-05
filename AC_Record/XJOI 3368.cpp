#include<bits/stdc++.h>
using namespace std;
long long f[30][30], n, m;
int main(){
	cin >> n >> m;
	f[1][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++){
			if(i == 1 && j == 1) continue;
			f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1];
		}
	cout << f[n][m];
	return 0;
}
