#include<bits/stdc++.h>
using namespace std;
int n, m, a[100010], d[100010][20];
int power[20];
int x, y;
int t;
int main(){
    power[0] = 1;
    for(int i = 1; i < 20; i++) power[i] = power[i - 1] * 2;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 20; i++) d[n][i] = a[n];  
    for(int i = n - 1; i >= 1; i--){
        d[i][0] = a[i];
        for(int j = 1; j < 20; j++)
            if(i + power[j - 1] <= n)
                d[i][j] = max(d[i][j - 1], d[i + power[j - 1]][j - 1]);
            else 
                d[i][j] = d[i][j - 1];
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        t = floor(log2(y - x));
        printf("%d\n", max(d[x][t], d[y - power[t] + 1][t]));
    }
    return 0;
}

