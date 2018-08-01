#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL x, y, m, n, L;
LL a, b, c, t, ans;
LL gcd(LL x, LL y) {
    LL m = x % y;
    while(m) { x = y; y = m; m = x % y; }
    return y;
}
void exgcd(LL x, LL y, LL &a, LL &b) {
    if(y == 0) { a = 1; b = 0; return; }
    exgcd(y, x % y, b, a);
    b -= (x / y) * a;
    return;
}
int main() {
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L);
    t = gcd(n - m, L);
    if((x - y) % t != 0) {
        printf("Impossible");
        return 0;
    }
    a = (x - y) / t; b = (n - m) / t; c = L / t;
    x = 0; y = 0;
    exgcd(b, c, x, y);
    ans = a * x % c;
    if(ans < 0) ans += c;
    printf("%lld\n", ans);
    return 0;
}

