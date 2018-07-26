#include<cstdio>
#include<cstring>
int m, t, n;
double p[1010][40], dp[40][40], P[1010], P2[1010], ans, ans2;
int main(){
    scanf("%d%d%d", &m, &t, &n);
    while(!(m == 0 && t == 0 && n == 0)){
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= t; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%lf", &p[i][j]);
        memset(P, 0, sizeof(P));
        memset(P2, 0, sizeof(P2));
        for(int i = 1; i <= t; ++i){
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for(int j = 1; j <= m; ++j)
                for(int k = 0; k <= j; ++k)
                    if(k == 0) dp[j][0] = dp[j - 1][0] * (1 - p[i][j]);
                    else dp[j][k] = dp[j - 1][k - 1] * p[i][j] + dp[j - 1][k] * (1 - p[i][j]);
            for(int j = 1; j < n; ++j) P[i] += dp[m][j];
            for(int j = 1; j <= m; ++j) P2[i] += dp[m][j];
        }
        ans = 1.0;
        for(int i = 1; i <= t; ++i) ans *= P[i];
        ans2 = 1.0;
        for(int i = 1; i <= t; ++i) ans2 *= P2[i];
        printf("%.3lf\n", ans2 - ans);
        scanf("%d%d%d", &m, &t, &n);
    }
    return 0;
}

