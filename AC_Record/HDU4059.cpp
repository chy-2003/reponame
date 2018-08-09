#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const LL mod = 1000000007;
LL n;
LL len, q[40];
LL INV;
LL fast_pow(LL x, LL y) {
    if(y == 0) return 1LL;
    LL t = fast_pow(x, y / 2);
    t = (t * t) % mod;
    if(y % 2 == 1) t = (t * x) % mod;
    return t;
}
LL Q(LL x) {
    LL M = mod;
    LL xx = ((3LL * x % M * x % M + 3LL * x % M) % M + M - 1) % M;
    LL re = x * ((x + 1LL) % M) % M * ((x * 2LL % M + 1) % M) % M;
    re = re * xx % M;
    re = re * INV % M;
    return re;
}
void work() {
    scanf("%lld", &n);
    len = 0;
    LL t = n;
    for(LL i = 2; i * i <= n; i++) 
        if(t % i == 0) {
            q[++len] = i;
            while(t % i == 0) t /= i;
        }
    if(t > 1) q[++len] = t;
    LL ans = Q(n);
    for(LL i = 1; i < 1 << len; i++) {
        LL cnt = 1, num = 0;
        for(LL j = 1; j <= len; j++)
            if((i >> (j - 1)) & 1) {
                cnt = cnt * q[j] % mod;
                num++;
            }
        LL t = Q(n / cnt);
        t = t * cnt % mod * cnt % mod * cnt % mod * cnt % mod;
        if(num % 2 == 1)
            ans = ((ans - t) % mod + mod) % mod;
        if(num % 2 == 0)
            ans = (ans + t) % mod;
    }
    printf("%lld\n", ans);
}
int main() {
    LL t;
    INV = fast_pow(30, mod - 2);
    scanf("%lld", &t);
    for(LL i = 1; i <= t; i++) work();
    return 0;
}

