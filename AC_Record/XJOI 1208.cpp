//XJOI 1208
#include<bits/stdc++.h>
using namespace std;
int n, m, a[110][110];
int get_int(){
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    int num = 0;
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
int get_bit(){
    char ch = getchar();
    while(ch != '?' && ch != 'W' && ch != 'B') ch = getchar();
    if(ch == '?') return -1;
    if(ch == 'W') return 1;
    if(ch == 'B') return 0;
}
int main(){
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
          a[i][j] = get_bit();
        int b = 1;
        for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
          if(a[i][j] != -1)
          if(((i + j) % 2) ^ a[i][j] == 1){
            b = 0;
          }
        if(b == 1){
            printf("Possible\n");
            continue;
        }
        b = 1;
        for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
          if(a[i][j] != -1)
          if(((i + j) % 2) ^ a[i][j] == 0){
            b = 0;
          }
        if(b == 1){
            printf("Possible\n");
        } else
        printf("Impossible\n");
    }
    return 0;
}