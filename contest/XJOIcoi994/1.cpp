#include <cstdio>
#include <cstring>
#include <algorithm>
int fish[20][20], dp[20][20][17000];
int T, Maxx, Maxy, Ax, Q, N, x, y, D, L, time;
int calc(int x) {
    int ans = 0;
    for(int i = 0; i < N; i++)
        if((x >> i) & 1) ans++;
    return ans;
}
int main() {
    scanf("%d", &T);
    scanf("%d%d", &Maxx, &Maxy);
    scanf("%d%d", &Ax, &Q);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d%d%d", &x, &y, &D, &L, &time);
        if(x == 0) {
            int l, r;
            for(int j = time; j <= T; j++) {
                if(j == time) {
                    r = 0; l = 0 - L;
                }
                if(j > time) {
                    r += D; l += D;
                }
                for(int k = std::max(0, l); k <= std::min(r, Maxx); k++)
                    fish[j][k] |= 1 << i;
            }
        }
        if(x == Maxx) {
            int l, r;
            for(int j = time; j <= T; j++) {
                if(j == time) {
                    l = Maxx; r = l + L;
                }
                if(j > time) {
                    r -= D; l -= D;
                }
                for(int k = std::max(0, l); k <= std::min(r, Maxx); k++)
                    fish[j][k] |= 1 << i;
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    for(int i = -Q; i <= Q; i++)
        if(Ax + i >= 0 && Ax + i <= Maxx)
            dp[0][Ax + i][0] = 1;
    dp[0][Ax][fish[0][Ax]] = 1;
    int ans = 0;
    for(int t = 0; t < T; t++)
        for(int i = 0; i <= Maxx; i++)
            for(int j = 0; j < 1 << N; j++)
                if(dp[t][i][j]) {
                    dp[t + 1][i][j | fish[t + 1][i]] = 1;
                    for(int q = -Q; q <= Q; q++)
                        if(i + q >= 0 && i + q <= Maxx)
                            dp[t + 1][i + q][j] = 1;
                    ans = std::max(ans, calc(j));
                }
    for(int i = 0; i <= Maxx; i++)
        for(int j = 0; j < 1 << N; j++)
            if(dp[T][i][j])
                ans = std::max(ans, calc(j));
    printf("%d\n", ans);
    return 0;
}
