#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k, x, y, z;
int lp = 0, f[310], lin[610], nxt[610], val[610];
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
int dp[310][2][310];
void dfs(int pos, int fa) {
    dp[pos][0][0] = dp[pos][1][1] = 0;
    for(int t = f[pos]; t; t = nxt[t]) {
        if(lin[t] == fa) continue;
        dfs(lin[t], pos);
        for(int sum = n; sum >= 0; sum--) {
            int rec = INF;
            for(int i = 0; i <= sum; i++) rec = min(rec, dp[pos][0][sum - i] + dp[lin[t]][0][i]);
            for(int i = 1; i <= sum; i++) rec = min(rec, dp[pos][0][sum - i] + dp[lin[t]][1][i]);
            dp[pos][0][sum] = rec;
        }
        for(int sum = n; sum >= 1; sum--) {
            int rec = INF;
            for(int i = 0; i < sum; i++) rec = min(rec, dp[pos][1][sum - i] + dp[lin[t]][0][i]);
            for(int i = 1; i < sum; i++) rec = min(rec, dp[pos][1][sum - i] + dp[lin[t]][1][i] + val[t]);
            dp[pos][1][sum] = rec;
        }
    }
    return;
}
void dfs2(int pos, int fa) {
    dp[pos][0][0] = dp[pos][1][1] = 0;
    for(int t = f[pos]; t; t = nxt[t]) {
        if(lin[t] == fa) continue;
        dfs2(lin[t], pos);
        for(int sum = n; sum >= 0; sum--) {
            int rec = INF;
            for(int i = 0; i <= sum; i++) rec = min(rec, dp[pos][0][sum - i] + dp[lin[t]][0][i] + val[t]);
            for(int i = 1; i <= sum; i++) rec = min(rec, dp[pos][0][sum - i] + dp[lin[t]][1][i]);
            dp[pos][0][sum] = rec;
        }
        for(int sum = n; sum >= 1; sum--) {
            int rec = INF;
            for(int i = 0; i < sum; i++) rec = min(rec, dp[pos][1][sum - i] + dp[lin[t]][0][i]);
            for(int i = 1; i < sum; i++) rec = min(rec, dp[pos][1][sum - i] + dp[lin[t]][1][i] + val[t]);
            dp[pos][1][sum] = rec;
        }
    }
    return;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    if(n - k < m - 1) {
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z); add(y, x, z);
    }
    memset(dp, 0x3f, sizeof(dp));
    if(m == 2) dfs2(1, 1); else dfs(1, 1);
    printf("%d\n", dp[1][1][k]);
    return 0;
}
