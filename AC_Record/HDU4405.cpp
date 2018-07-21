#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[100010];
double g[100010];
int x, y;
int main(){
    scanf("%d%d", &n, &m);
    while(!(n == 0 && m == 0)){
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            f[x] = y;
        }
        memset(g, 0, sizeof(g));
        for(int i = n - 1; i >= 0; i--){
            if(f[i]){
                g[i] = g[f[i]];
                continue;
            }
            for(int j = 1; j <= 6; j++) g[i] += g[i + j];
            g[i] /= 6.0;
            g[i] += 1;
        }
        printf("%.4lf\n", g[0]);
        scanf("%d%d", &n, &m);
    }
    return 0;
}

