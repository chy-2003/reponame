#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = 1010;
char ch1[MAXLEN], ch2[MAXLEN];
int f[MAXLEN][MAXLEN], l1, l2;
int main(){
    scanf("%s", ch1 + 1);
    scanf("%s", ch2 + 1);
    l1 = strlen(ch1 + 1);
    l2 = strlen(ch2 + 1);
    for(int i = 1; i <= l1; i++)
        for(int j = 1; j <= l2; j++)
            if(ch1[i] == ch2[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    printf("%d\n", f[l1][l2]);
    return 0;
}
