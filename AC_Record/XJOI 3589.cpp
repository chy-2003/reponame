#include<bits/stdc++.h>
using namespace std;
int a[100010][11], n, x, t;
int main(){
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x, &t);
        a[t][x]++;
    }
    for(int i = 0; i <= 3; i++) a[1][i] = 0;
    for(int i = 7; i <= 10; i++) a[1][i] = 0;
    for(int i = 2; i <= 100000; i++){
        a[i][0] = max(a[i - 1][0], a[i - 1][1]) + a[i][0];
        a[i][10] = max(a[i - 1][10], a[i - 1][9]) + a[i][10];
        for(int j = 1; j < 10; j++)
            a[i][j] = max(max(a[i - 1][j - 1], a[i - 1][j]), a[i - 1][j + 1]) + a[i][j];
        for(int j = 0; j <= 4 - i; j++) a[i][j] = 0;
        for(int j = 6 + i; j <= 10; j++) a[i][j] = 0;
    }
    int ans = 0;
    for(int i = 0; i <= 10; i++) ans = max(ans, a[100000][i]);
    printf("%d", ans);
    return 0;
}
