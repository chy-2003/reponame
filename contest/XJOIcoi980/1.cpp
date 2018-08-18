#include <cstdio>
#include <cstring>
int n, m, a[60][60], b[60][60], num, cnt[310], f[310], ans;
void dfs(int x, int y) {
    cnt[num]++;
    a[x][y] = 1;
    b[x][y] = num;
    if(a[x - 1][y] == 0) dfs(x - 1, y);
    if(a[x][y + 1] == 0) dfs(x, y + 1);
    if(a[x + 1][y] == 0) dfs(x + 1, y);
    if(a[x][y - 1] == 0) dfs(x, y - 1);
    return;
}
int min(int x, int y) { return (x < y) ? x : y; }
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++) { a[i][0] = 1; a[i][m + 1] = 1; }
    for(int i = 1; i <= m; i++) { a[0][i] = 1; a[n + 1][i] = 1; }
    num = 0;
    memset(b, 0, sizeof(b));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 0) {
                num++;
                dfs(i, j);
            }
    ans = n * m;
    for(int i1 = 1; i1 <= n; i1++) {
        int b1 = 0;
        for(int j1 = 1; j1 <= m; j1++) {
            int b2 = 0;
            for(int i2 = n; i2 >= i1; i2--) {
                int b3 = 0;
                memset(f, 0, sizeof(f));
                for(int j2 = j1; j2 <= m; j2++) {
//                  if((j2 - j1 + 1) * (i2 - i1 + 1) > ans) break;
                    for(int i = i1; i <= i2; i++) if(b[i][j2] != 0) f[b[i][j2]]++;
                    int b4 = 1;
                    for(int i = 1; i <= num; i++)
                        if(f[i] == 0) {
                            b4 = 0;
                            break;
                        }
///                 printf("i1 = %d j1 = %d i2 = %d j2 = %d b4 = %d\n", i1, j1, i2, j2, b4);
                    if(b4) {
                        ans = min(ans, (j2 - j1 + 1) * (i2 - i1 + 1));
//                      printf("i1 = %d j1 = %d i2 = %d j2 = %d ans = %d\n", i1, j1, i2, j2, ans);
                        b3 = 1;
                        break;
                    }
                }
//              printf("i1 = %d j1 = %d i2 = %d b3 = %d\n", i1, j1, i2, b3);
                if(b3 == 0) break; else b2 = 1;
            }
//          printf("i1 = %d j1 = %d b2 = %d\n", i1, j1, b2);
            if(b2 == 0) break; else b1 = 1;
        }
//      printf("i1 = %d b1 = %d\n", i1, b1);
        if(b1 == 0) break;
    }
    printf("%d\n", ans);
    return 0;
}
