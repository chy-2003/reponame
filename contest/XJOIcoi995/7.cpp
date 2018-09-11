#include <cstdio>
#include <cstring>
#include <algorithm>
 
const long long MAXN = 1000010;
long long n, dis[MAXN], P[MAXN], C[MAXN];
long long sum[MAXN], sump[MAXN], dp[MAXN];
long long l, r, q[MAXN];
 
double s(long long i, long long j) {
    return 1.0 * ((dp[i] + sum[i]) - (dp[j] + sum[j])) / (sump[i] - sump[j]);
}
 
int main() {
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++) scanf("%lld%lld%lld", &dis[i], &P[i], &C[i]);
    memset(sum, 0, sizeof(sum));
    memset(sump, 0, sizeof(sump));
    for(long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + dis[i] * P[i];
    for(long long i = 1; i <= n; i++) sump[i] = sump[i - 1] + P[i];
    dp[0] = 0LL;
    l = r = 0;
    memset(q, 0, sizeof(q));
    for(long long i = 1; i <= n; i++) {
        while(l < r && s(q[l + 1], q[l]) < 1.0 * dis[i]) l++;
        dp[i] = dp[q[l]] + dis[i] * (sump[i] - sump[q[l]]) - (sum[i] - sum[q[l]]) + C[i];
        while(l < r && s(i, q[r - 1]) < s(q[r], q[r - 1])) r--;
        q[++r] = i;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
