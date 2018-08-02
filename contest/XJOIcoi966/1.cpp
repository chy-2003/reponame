#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const LL MAXN = 1010, MAXM = 1000010;
LL n, m, s_rain, t_rain, S, h, k, t, v;
LL ti[MAXN], V[MAXN];
LL lp = 0, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1];
inline void add(LL x, LL y, LL z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
void collect(LL pos, LL fa) {
    for(LL t = f[pos]; t; t = nxt[t]) {
        if(lin[t] == fa) continue;
        collect(lin[t], pos);
        ti[pos] = max(ti[pos], ti[lin[t]] + V[lin[t]] * val[t]);
        V[pos] += V[lin[t]];
    }
    return;
}
int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &s_rain, &t_rain);
    memset(V, 0, sizeof(V));
    memset(ti, 0, sizeof(ti));
    for(LL i = 1; i <= m; i++) {
        scanf("%lld%lld%lld%lld", &S, &h, &k, &t);
        v = min(s_rain * t_rain, h) * S;
        V[k] += v; ti[k] = max(ti[k], v * t);
    }
    for(LL i = 1; i < n; i++) {
        scanf("%lld%lld", &k, &t);
        add(k, i, t);
    }
    collect(n, 0);
    printf("%lld\n", ti[n]);
    return 0;
}
