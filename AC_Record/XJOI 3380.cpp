//XJOI 3380
#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010][1010], f[1010][1010], g[1010], ans = 0;
int l1, l2, c[1010], d[1010], l;
char ch;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> ch;
			a[i][j] = (ch == '1') ? 1 : 0;
		}
	for(int i = 1; i <= n; i++) g[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = (a[i][j] == 1) ? (f[i][j - 1] + 1) : 0;
	for(int i = 1; i <= m; i++){
		l1 = 0; l2 = 0;
		for(int j = 1; j <= n; j++)
			if(a[g[j]][i] == 1){
				l1++;
				c[l1] = g[j];
			} else{
				l2++;
				d[l2] = g[j];
			}
		l = 0;
		for(int j = 1; j <= l1; j++){
			l++;
			g[l] = c[j];
		}
		for(int j = 1; j <= l2; j++){
			l++;
			g[l] = d[j];
		}
		for(int j = 1; j <= n; j++) ans = max(ans, j * f[g[j]][i]);
	}
	printf("%d", ans);
	return 0;
}