#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const LL MAXN = 100010;
const LL mod = 1000000007;
LL fact[MAXN << 1], INV[MAXN << 1];
LL fast_pow(LL x, LL y) {
    if(y == 0) return 1;
    LL t = fast_pow(x, y / 2);
    t = t * t % mod;
    if(y % 2 == 1) t = t * x % mod;
    return t;
}
void init() {
    fact[0] = fact[1] = 1;
    for(LL i = 2; i <= 200010; i++) fact[i] = fact[i - 1] * i % mod;
    INV[200010] = fast_pow(fact[200010], mod - 2);
    for(LL i = 200009; i >= 0; i--) INV[i] = INV[i + 1] * (i + 1) % mod;
    return;
}
LL n, m;
LL C(LL n, LL m) { return fact[n] * INV[m] % mod * INV[n - m] % mod; }
LL cal(LL x, LL n, LL m) {
    if(n == 0) return 1;
    LL ans = 0;
    for(LL i = 0; i <= m && x * i <= n; i++) {
        LL t = C(m, i) * C(n - x * i + m - 1, m - 1) % mod;
        if(i % 2 == 0) ans = (ans + t) % mod; else ans = ((ans - t) % mod + mod) % mod;
    }
    return ans;
}
void work() {
    scanf("%lld%lld", &n, &m);
    if(n == 1) {
        printf("%lld\n", 1LL);
        return;
    }
    LL ans = 0;
    for(LL i = 2; i <= n; i++) ans = (ans + cal(i, n - i, m - 1)) % mod; 
    printf("%lld\n", ans);
    return;
}
int main() {
    init();
    LL t;
    scanf("%lld", &t);
    for(LL i = 1; i <= t; i++) work();
    return 0;
}

