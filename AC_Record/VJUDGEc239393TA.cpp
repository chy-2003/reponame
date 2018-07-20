#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, a[11][11];
int l, r, q1[1 << 15], q2[1 << 14];
int dp[1 << 12][11];
int main(){
    scanf("%d", &n);
    while(n > 0){
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                scanf("%d", &a[i][j]);
        for(int k = 0; k <= n; k++)
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        l = 0; r = 0;
        memset(dp, 255, sizeof(dp));
        dp[0][0] = 0;
        r++;
        q1[r] = 0; q2[r] = 0;
        int ans = 2000000000;
        while(l < r){
            l++;
            int t1 = q1[l], t2 = q2[l];
            for(int i = 0; i <= n; i++)
                if(dp[t1 | (1 << i)][i] == -1 || dp[t1 | (1 << i)][i] > dp[t1][t2] + a[t2][i]){
                    dp[t1 | (1 << i)][i] = dp[t1][t2] + a[t2][i];
                    r++; q1[r] = t1 | (1 << i); q2[r] = i;
                    if(q1[r] == ((1 << (n + 1)) - 1) && q2[r] == 0)
                        ans = min(ans, dp[q1[r]][q2[r]]);
                }
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}

