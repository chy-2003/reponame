#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#define LL long long
using namespace std;
LL a, bb, L;
LL cnt[100010], cnt2[100010];
LL l, b[1000010], q[100010];
void init() {
    l = 0;
    for(LL i = 2; i <= 1000000; ++i) {
        if(b[i] == 0) q[++l] = i;
        for(LL j = 1; j <= l; j++) {
            if(1LL * q[j] * i <= 1000000LL) b[q[j] * i] = 1; else break;
            if(i % q[j] == 0) break;
        }
    }
    return;
}
LL gcd(LL x, LL y) {
    LL m = x % y;
    while(m) { x = y; y = m; m = x % y; }
    return y;
}
LL lcm(LL x, LL y) { return x * y / gcd(x, y); }
void devide(LL t) {
    for(LL i = 1; i <= l; i++) {
        if(q[i] > t) break;
        while(t % q[i] == 0) cnt[i]++, t /= q[i];
    }
    return;
}
void devide2(LL t) {
    for(LL i = 1; i <= l; i++) {
        if(q[i] > t) break;
        while(t % q[i] == 0) cnt2[i]++, t /= q[i];
    }
    return;
}
void work() {
    scanf("%lld%lld%lld", &a, &bb, &L);
    LL t = lcm(a, bb);
    if(L % t != 0) {
        printf("impossible\n");
        return;
    }
    memset(cnt, 0, sizeof(cnt));
    devide(t);
    memset(cnt2, 0, sizeof(cnt2));
    devide2(L / t);
    LL ans = 1;
    for(LL i = 1; i <= l; i++) 
        if(cnt2[i] > 0)  
            for(LL j = 1; j <= cnt[i] + cnt2[i]; j++) 
                ans *= q[i];
    printf("%lld\n", ans);
    return;
}
int main() {
    init();
    LL t;
    scanf("%lld", &t);
    for(LL i = 1; i <= t; i++) printf("Case %lld: ", i), work();
    return 0;
}

