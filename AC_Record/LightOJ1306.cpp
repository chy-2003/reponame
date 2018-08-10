#include <cstdio>
#define LL long long
using namespace std;
LL A, B, C, x1, x2, y1, y2;
LL xl, xr, yl, yr;
void swap(LL & x, LL & y) {
    LL t = x; x = y; y = t;
    return;
}
LL gcd(LL x, LL y) {
    LL m = x % y;
    while(m) { x = y; y = m; m = x % y; }
    return y;
}
void exgcd(LL A, LL B, LL & x, LL & y) {
    if(B == 0) {
        if(A == 1) x = 1; else x = -1;
        y = 0; return;
    }
    exgcd(B, A % B, y, x);
    y -= A / B * x;
    return;
}
LL xxl, xxr, yyl, yyr;
void work2() {
    if(A == 0 && B == 0) {
        if(C != 0) printf("0\n"); else printf("%lld\n", (x2 - x1 + 1) * (y2 - y1 + 1));
        return;
    }
    if(B == 0) {
        if(C % A != 0) {
            printf("0\n");
            return;
        }
        LL t = C / A;
        if(x1 <= t && t <= x2) printf("%lld\n", y2 - y1 + 1); else printf("0\n");
        return;
    }
    if(A == 0) {
        if(C % B != 0) {
            printf("0\n");
            return;
        }
        LL t = C / B;
        if(y1 <= t && t <= y2) printf("%lld\n", x2 - x1 + 1); else printf("0\n");
        return;
    }
}
void work() {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &A, &B, &C, &x1, &x2, &y1, &y2);
    C = -C;
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    if(B == 0 || A == 0) {
        work2();
        return;
    }
    LL t = gcd(A, B);
    if(t < 0) t = -t;
    if(C % t != 0) {
        printf("0\n");
        return;
    }
    A /= t; B /= t; C /= t;
    LL x0, y0;
    exgcd(A, B, x0, y0);
    x0 *= C; y0 *= C;
    xxl = x1 - x0; xxr = x2 - x0;
    yyl = y1 - y0; yyr = y2 - y0;
    xl = xxl / B; xr = xxr / B;
    yl = yyl / (-A); yr = yyr / (-A);
    if(xl * B < xxl) xl += (B > 0) ? 1 : -1;
    if(xr * B > xxr) xr -= (B > 0) ? 1 : -1;
    if(yl * (-A) < yyl) yl += ((-A) > 0) ? 1 : -1;
    if(yr * (-A) > yyr) yr -= ((-A) > 0) ? 1 : -1;
    if(x0 + B * xl > x2 || x0 + B * xr < x1) { printf("0\n"); return; } 
    if(y0 - A * yl > y2 || y0 - A * yr < y1) { printf("0\n"); return; }
    if(xl > xr) swap(xl, xr);
    if(yl > yr) swap(yl, yr);
    if(xl < yl) { 
        if(xr < yl) { printf("0\n"); return; }
        if(yl <= xr && xr < yr) { printf("%lld\n", xr - yl + 1); return; }
        if(yr <= xr) { printf("%lld\n", yr - yl + 1); return; }
    }
    if(yl <= xl && xl <= yr) {
        if(xr < yr) { printf("%lld\n", xr - xl + 1); return; }
        if(yr <= xr) { printf("%lld\n", yr - xl + 1); return; }
    }
    if(xl > yr) { printf("0\n"); return; }
}
int main() {
    LL t;
    scanf("%lld", &t);
    for(LL i = 1; i <= t; i++) printf("Case %lld: ", i), work();
    return 0;
}

