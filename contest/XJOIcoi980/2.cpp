#include <cstdio>
#include <cstring>
int n, k, x, y;
int val[310];
int lp = 0, f[310], lin[310], nxt[310];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int dp[310][310];
void dfs(int x) {
    dp[x][0] = 0;
    dp[x][1] = val[x];
    for(int t = f[x]; t; t = nxt[t]) {
        dfs(lin[t]);
        for(int i = k; i >= 2; i--) {
            for(int j = 1; j <= k; j++) {
                if(i - j < 1) break;
                if(dp[lin[t]][j] == -1) continue;
                if(dp[x][i - j] == -1) continue;
                if(dp[x][i] < dp[x][i - j] + dp[lin[t]][j])
                    dp[x][i] = dp[x][i - j] + dp[lin[t]][j];
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        val[i] = y;
        add(x, i);
    }
    memset(dp, 255, sizeof(dp));
    val[0] = 0;
    k++;
    dfs(0);
    printf("%d\n", dp[0][k]);
    return 0;
}

