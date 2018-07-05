//XJOI 1211
#include<bits/stdc++.h>
using namespace std;
int a[110][110];
const int bz[2][8] ={{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1 ,-1, -1}};
int get_bit(){
    char ch = getchar();
    while(ch != '*' && ch != '?') ch = getchar();
    return (ch == '*')? -1 : 0;
}
int main(){
    int n, m;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
     for(int j = 1; j <= m; j++)
      a[i][j] = get_bit();
    for(int i = 1; i <= n; i++)
     for(int j = 1; j <= m; j++){
        if(a[i][j] == -1) continue;
        for(int k = 0; k < 8; k++)
         if(a[i + bz[0][k]][j + bz[1][k]] == -1) a[i][j]++;
     }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
         if(a[i][j] == -1) printf("*"); else printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}