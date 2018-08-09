#include <cstdio>
#define LL long long
const LL N = 1000010, mod = 1000000007;
LL a[N], n, ans, f[N], P[N], x;
int main() {
    P[0] = 1; for(LL i = 1; i < N; i++) P[i] = P[i - 1] * 2 % mod;
    scanf("%lld", &n); for(LL i = 1; i <= n; i++) scanf("%lld", &x), a[x]++;
    for(LL i = N - 1; i > 1; i--) {
        x = 0; for(LL j = i; j < N; j += i) x += a[j];
        if(x == 0) continue;
        f[i] = x % mod * P[x - 1] % mod;
        for(LL j = i + i; j < N; j += i) f[i] = ((f[i] - f[j]) % mod + mod) % mod;
        ans = (ans + f[i] * i % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

