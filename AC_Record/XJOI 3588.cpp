#include<bits/stdc++.h>
using namespace std;
char ch[1010];
int l, x, y, rec[1010][1010], f[1010];
int main(){
	scanf("%s", ch + 1);
	l = strlen(ch + 1);
	memset(rec, 0, sizeof(rec));
	for(int i = 1; i <= l; i++){
		x = i; y = i;
		while(x >= 1 && y <= l){
			if(ch[x] == ch[y]) rec[x][y] = 1; else break;
			x--; y++;
		}
	}
	for(int i = 1; i < l; i++){
		x = i; y = i + 1;
		while(x >= 1 && y <= l){
			if(ch[x] == ch[y]) rec[x][y] = 1; else break;
			x--; y++;
		}
	}
	for(int i = 1; i <= l; i++) f[i] = 1010;
	for(int i = 1; i <= l; i++)
		for(int j = 1; j <= i; j++)
			if(rec[j][i] == 1)
				f[i] = min(f[i], f[j - 1] + 1);
	printf("%d", f[l]);
	return 0;
}
