#include<bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, f[410][30][30], a[30][30];
int get_int(){
    int t = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}
int get_bit(){
    char ch = getchar();
    while(ch != '.' && ch != '#') ch = getchar();
    return (ch == '.') ? 1 : 0;
}
int main(){
    n = get_int(); m = get_int();
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            a[i][j] = get_bit();
            if(a[i][j] == 0) cnt++;
        }
    memset(f, 255, sizeof(f));
    f[1][1][1] = a[1][1];
//    printf("*\n");
    for(int k = 1; k < n * m && k < cnt; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
//                printf("%d", a[i][j]);
                if(f[k][i][j] == -1) continue;
                for(int t = 0; t < 4; t++){
                    int x = i + bz[0][t];
                    int y = j + bz[1][t];
                    if(f[k + 1][x][y] == -1) f[k + 1][x][y] = f[k][i][j] + a[x][y]; else
                    f[k + 1][x][y] = min(f[k + 1][x][y], f[k][i][j] + a[x][y]);
                }
            }
//            printf("\n");
        }
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <= m; j++) printf("%4d ", f[k + 1][i][j]);
//            printf("\n");
//        }
    }
    int ans = 10010;
    for(int i = 1; i <= n * m && i <= cnt; i++) if(f[i][n][m] != -1) ans = min(ans, f[i][n][m]);
    printf("%d\n", (ans != 10010) ? ans : -1);
    return 0;
}

