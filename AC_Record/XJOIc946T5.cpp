#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL s, t, n, m, a[100010], b[100010], c[100010], dis[100010], vis[100010], rec[100010];
void p(long long t){
    if(t == 0) return;
    p(rec[t]);
    printf("%lld ", t);
    return;
}
int main(){
    scanf("%lld%lld", &s, &t);
    scanf("%lld%lld", &n, &m);
    for(LL i = 1; i <= m; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    memset(dis, 255, sizeof(dis));
    for(LL i = 1; i <= n; i++) rec[i] = 1010;
    dis[s] = 0;
    vis[s] = 0;
    rec[s] = 0;
    for(LL i = 1; i <= n; i++)
        for(LL j = 1; j <= m; j++)
            if(dis[a[j]] > -1)
                if(dis[b[j]] < dis[a[j]] + c[j] || dis[b[j]] == dis[a[j]] + c[j] && a[j] < rec[b[j]]){
                    rec[b[j]] = a[j];
                    dis[b[j]] = dis[a[j]] + c[j];
                }
    printf("%lld\n", dis[t]);
    p(t);
    return 0;
}
