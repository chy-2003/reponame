#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 999983, MAXNUM = 3375010;
int n, m, a[10][2];
int lp, f[mod + 10], lin[MAXNUM], nxt[MAXNUM], val[MAXNUM];
int ans;
void add(int x) {
    int y = (x % mod + mod) % mod;
    for(int t = f[y]; t; t = nxt[t]) {
        if(lin[t] != x) continue;
        val[t]++;
        return;
    }
    lin[++lp] = x; nxt[lp] = f[y]; f[y] = lp; val[lp] = 1;
    return;
}
int power(int x, int y) {
    int t = 1;
    for(int i = 1; i <= y; i++) t = t * x;
    return t;
}
int ask(int x) {
    int y = (x % mod + mod) % mod;
    for(int t = f[y]; t; t = nxt[t]) {
        if(lin[t] != x) continue;
        return val[t];
    }
    return 0;
}
void hash(int x) {
    if(x == 1) {
        for(int i = 1; i <= m; i++)
            add(a[1][0] * power(i, a[1][1]));
        return;
    }
    if(x == 2) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                add(a[1][0] * power(i, a[1][1]) + a[2][0] * power(j, a[2][1]));
        return;
    }
    if(x == 3) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    add(a[1][0] * power(i, a[1][1]) + a[2][0] * power(j, a[2][1]) + a[3][0] * power(k, a[3][1]));
        return;
    }
    return;
}
void count(int x, int y) {
    ans = 0;
    if(y == 1) {
        for(int i = 1; i <= m; i++)
            ans += ask(-a[x + 1][0] * power(i, a[x + 1][1]));
        return;
    }
    if(y == 2) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                ans += ask(-a[x + 1][0] * power(i, a[x + 1][1]) - a[x + 2][0] * power(j, a[x + 2][1]));
        return;
    }
    if(y == 3) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    ans += ask(-a[x + 1][0] * power(i, a[x + 1][1]) - a[x + 2][0] * power(j, a[x + 2][1]) - a[x + 3][0] * power(k, a[x + 3][1]));
        return;
    }
    return;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i][0], &a[i][1]);
    if(n == 1) {
        if(a[1] == 0) printf("1\n"); else printf("0\n");
        return 0;
    }
    hash((n + 1) / 2);
    count((n + 1) / 2, n - (n + 1) / 2);
    printf("%d\n", ans);
    return 0;
}
