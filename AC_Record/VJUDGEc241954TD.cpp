#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200010;
long long lp = 0, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1];
inline void add(long long x, long long y, long long z) {
    lin[++lp] = y;
    nxt[lp] = f[x];
    val[lp] = z;
    f[x] = lp;
    return;
}
long long n, x, y, z, dis[MAXN], father[MAXN], start, end;
long long maxnum, id;
long long rec[MAXN];
void dfs(long long pos, long long fa, long long s){
    father[pos] = fa; dis[pos] = s;
    for(long long t = f[pos]; t; t = nxt[t]){
        if(lin[t] == fa) continue;
        dfs(lin[t], pos, s + val[t]);
    }
    return;
}
long long l, r, t, ans, d;
void get_(long long pos, long long fa, long long s) {
    d = max(d, s);
    for(long long t = f[pos]; t; t = nxt[t]){
        if(lin[t] == fa || rec[lin[t]] == 1) continue;
        get_(lin[t], pos, s + val[t]);
    }
    return;
}
int main(){
    scanf("%lld", &n);
    for(long long i = 1; i < n; i++){
        scanf("%lld%lld%lld", &x, &y, &z);
        add(x, y, z); add(y, x, z);
    }
    dfs(1, 0, 0);
    maxnum = 0;
    for(long long i = 1; i <= n; i++)
        if(dis[i] > maxnum){
            maxnum = dis[i];
            id = i;
        }
    start = id;
    dfs(start, 0, 0);
    maxnum = 0;
    for(long long i = 1; i <= n; i++)
        if(dis[i] > maxnum){
            maxnum = dis[i];
            id = i;
        }
    printf("%lld\n", maxnum);
    end = id;
    memset(rec, 0, sizeof(rec));
    t = end;
    rec[t] = 1;
    while(t != start) {
        t = father[t];
        rec[t] = 1;
    }
    l = end; r = start;
    t = end;
    while(t != start) {
        d = 0;
        get_(t, 0, 0);
        if(d == dis[end] - dis[t]) l = t;
        if(d == dis[t] - dis[start]) {
            r = t;
            break;
        }
        t = father[t];
    }
    ans = 0;
    while(l != r){
        ans++;
        l = father[l];
    }
    printf("%lld\n", ans);
    return 0;
}

