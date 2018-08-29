#include <bits/stdc++.h>
using namespace std;
struct Node {
    long long val, monitor, pro;
    Node(long long val_ = 0, long long monitor_ = 0, long long pro_ = 0) { val = val_; monitor = monitor_; pro = pro_; }
};
long long n, m, b;
Node a[110];
long long dp[1100010];
bool cmp(Node x, Node y) {
    return x.monitor < y.monitor;
}
int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &b);
    for(long long i = 1; i <= n; i++) {
        long long x, k, mm;
        scanf("%I64d%I64d%I64d", &x, &k, &mm);
        long long t = 0;
        for(long long j = 1; j <= mm; j++) {
            long long y;
            scanf("%I64d", &y);
            t |= (1 << (y - 1));
        }
        a[i] = Node(x, k, t);
    }
    memset(dp, 255, sizeof(dp));
    sort(a + 1, a + n + 1, cmp);
    dp[0] = 0;
    long long ans = -1;
    for(long long i = 1; i <= n; i++) {
        for(long long j = 0; j < 1 << m; j++) {
            if(dp[j] == -1) continue;
            if(dp[j | a[i].pro] == -1) 
                dp[j | a[i].pro] = dp[j] + a[i].val;
            else
                dp[j | a[i].pro] = min(dp[j | a[i].pro], dp[j] + a[i].val);
        }
        if(dp[(1 << m) - 1] != -1) {
            if(ans != -1) 
                ans = min(ans, dp[(1 << m) - 1] + a[i].monitor * b);
            else 
                ans = dp[(1 << m) - 1] + a[i].monitor * b;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
