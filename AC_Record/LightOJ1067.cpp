#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#define LL long long
const LL MAXN = 1000000, mod = 1000003;
LL fact[MAXN + 10], INV[MAXN + 10];
LL fast_pow(LL x, LL y) {
    if(y == 0) return 1;
    LL t = fast_pow(x, y / 2);
    t = t * t % mod;
    if(y % 2 == 1) t = t * x % mod;
    return t;
}
void init() {
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % mod;
    INV[MAXN] = fast_pow(fact[MAXN], mod - 2);
    for(int i = MAXN - 1; i >= 0; i--) INV[i] = INV[i + 1] * (i + 1) % mod;
    return;
}
LL C(int x, int y) { return fact[x] * INV[y] % mod * INV[x - y] % mod; }
int main() {
    init();
    int t, x, y;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d%d", &x, &y);
        printf("Case %d: %lld\n", i, C(x, y));
    }
    return 0;
}

