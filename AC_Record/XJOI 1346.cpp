/*
轮        1  2  3  4   5   6   7   8   9   10  11   12
击球情况  /  /  /  7 2 9 / 8 1 8 / /   9 / /   8 /
各轮得分  30 27 19 9   18  9   20  20  20  20
累计总分  30 57 76 85  103 112 132 152 172 192
*/
#include<bits/stdc++.h>
using namespace std;
int l, a[30][2], f[13], rec[30];
char ch;
int get(char ch){
    if(ch == '/') return 10;
    return ch - '0';
}
int main(){
    l = 1;
    memset(a, 255, sizeof(a));
    while(scanf("%c", &ch) == 1){
        if(ch == ' ') continue;
        if(ch == '\n') break;
//      printf("*\n");
        if(a[l][0] != -1 && a[l][1] != -1) l++;
        if(a[l][0] == 10) l++;
        if(a[l][0] + a[l][1] == 10) l++;
        if(a[l][0] == -1) a[l][0] = get(ch);
        else{
            a[l][1] = get(ch);
            if(a[l][1] == 10)
            a[l][1] -= a[l][0];
        }
    }
	for(int i = l + 1; i <= 29; i++) a[i][0] = 0, a[i][1] = 0;
    for(int i = 1; i <= l; i++){
        if(a[i][0] != -1 && a[i][1] != -1 && a[i][0] + a[i][1] != 10){
            f[i] = a[i][0] + a[i][1];
		} else
        if(a[i][0] != -1 && a[i][1] != -1){
            f[i] = 10 + a[i + 1][0];
			if(i + 1 > l){ rec[i] = 1; break; }
		} else
        if(a[i][0] != -1 && a[i][1] == -1)
            if(a[i + 1][1] == -1){
                f[i] = 10 + a[i + 1][0] + a[i + 2][0];
				if(i + 2 > l){ rec[i] = 1; break; }
			}
            else{
                f[i] = 10 + a[i + 1][0] + a[i + 1][1];
				if(i + 1 > l){ rec[i] = 1; break; }
			}
    }
//  for(int i = 1; i <= 12; i++) printf("%d %d\n", a[i][0], a[i][1]);
    for(int i = 1; i <= l && rec[i] == 0; i++) printf("%d ", f[i]); printf("\n");
    for(int i = 1; i <= l && rec[i] == 0; i++){
        f[i] += f[i - 1];
        printf("%d ", f[i]);
    } printf("\n");
    return 0;
}
