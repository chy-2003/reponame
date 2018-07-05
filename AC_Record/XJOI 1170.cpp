//XJOI 1170
#include<bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, a[20][20];
int main(){
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int x = 1, y = 1, z = 1;
    a[x][y] = 1;
    for(int i = 1; i <= n; i++){
        a[0][i] = -1;
        a[n + 1][i] = -1;
        a[i][0] = -1;
        a[i][n + 1] = -1;
    }
    for(int i = 2; i <= n * n; i++){
        x += bz[0][z]; y += bz[1][z];
        if(a[x][y] != 0){
            x -= bz[0][z]; y -= bz[1][z];;
            z++; z %= 4;
            x += bz[0][z]; y += bz[1][z];
        }
        a[x][y] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
         printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}