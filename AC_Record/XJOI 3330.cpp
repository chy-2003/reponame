//XJOI 3330
#include<bits/stdc++.h>
using namespace std;
const int bz[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2}, {1, 2, 2, 1, -1, -2, -2, -1}};
int n, a[310][310], stx, sty, enx, eny;
int l, r, q[3][90010], x, y;
int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    scanf("%d%d", &stx, &sty);
    scanf("%d%d", &enx, &eny);
    a[stx][sty] = 1;
    r = 1; l = 0; q[0][1] = stx; q[1][1] = sty; q[2][1] = 0;
    if(stx == enx && sty == eny){
        printf("0");
        return 0;
    }
    while(l < r){
        l++;
        for(int i = 0; i < 8; i++){
            x = q[0][l] + bz[0][i];
            y = q[1][l] + bz[1][i];
            if(x < 0 || x >= n || y < 0 || y >= n) continue;
            if(a[x][y]) continue;
            r++;
            q[0][r] = x; q[1][r] = y; q[2][r] = q[2][l] + 1;
            a[x][y] = 1;
            if(x == enx && y == eny){
                printf("%d\n", q[2][r]);
                return 0;
            }
        }
    }
    return 0;
}