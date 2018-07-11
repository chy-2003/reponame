#include<bits/stdc++.h>
using namespace std;
int len;
char ch[200];
int f[210][210];
int main(){
	scanf("%s", ch + 1);
	len = strlen(ch + 1);
	for(int i = 1; i <= len; i++) f[i][i] = 1;
	for(int k = 2; k <= len; k++)
		for(int i = 1; i <= len - k + 1; i++){
			int j = i + k - 1;
			f[i][j] = 210;
			for(int t = i; t < j; t++) f[i][j] = min(f[i][j], f[i][t] + f[t + 1][j]);
			if(ch[i] == '(' && ch[j] == ')' || ch[i] == '[' && ch[j] == ']')
				f[i][j] = min(f[i][j], f[i + 1][j - 1]);
		}
	printf("%d\n", f[1][len]);
	return 0;
}
