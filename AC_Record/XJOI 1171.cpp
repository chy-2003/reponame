//XJOI 1171
#include<bits/stdc++.h>
using namespace std;
const int bz[2][2] = {{-1, 1}, {1, -1}};
int n, a[1010][1010];
int main(){
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int x = 1, y = 1, z = 0;
    for(int i = 1; i <= n * n - 1; i++){
        a[x][y] = i;
        x += bz[0][z]; y += bz[1][z];
        if(x < 1 && y > n){
            x = 2; y = n; z++; z %= 2;
        } else
        if(x > n && y < 1){
            y = 2; x = n; z++; z %= 2;
        } else
        if(x < 1){
            x++; z++; z %= 2;
        } else
        if(y < 1){
            y++; z++; z %= 2;
        } else
        if(x > n){
            x = n; y += 2; z++; z %= 2;
        } else
        if(y > n){
            y = n; x += 2; z++; z %= 2;
        }
         
    }
    a[x][y] = n * n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
         printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}