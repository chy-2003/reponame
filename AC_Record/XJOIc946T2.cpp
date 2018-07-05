#include<bits/stdc++.h>
using namespace std;
long long s, t, n, m, rec[1010][1010], a, b, c;
long long dis[1010], vis[1010], minnum, id, rec2[1010];
long long smaller(long long x, long long y){
    if(x == -1) return 0;
    if(y == -1) return 1;
    return (x < y) ? 1 : 0;
}
long long smaller2(long long x, long long y){
    if(rec[x][y] == -1) return 0;
    if(dis[y] == -1) return 1;
    if((rec[x][y] + dis[x] < dis[y]) || ((rec[x][y] + dis[x] == dis[y]) && rec2[y] > x))
        return 1; else return 0;
}
void p(long long x){
    if(x == 0) return;
    p(rec2[x]);
    printf("%lld ", x);
    return;
}
int main(){
    scanf("%lld%lld", &s, &t);
    scanf("%lld%lld", &n, &m);
    memset(rec, 255, sizeof(rec));
    for(long long i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        rec[a][b] = c;
        rec[b][a] = c;
    }
    memset(dis, 255, sizeof(dis));
    dis[s] = 0;
    rec2[s] = 0;
    for(long long i = 1; i < n; i++){
        minnum = -1;
        for(long long j = 1; j <= n; j++)
            if(vis[j] == 0 && smaller(dis[j], minnum)){
                minnum = dis[j];
                id = j;
            }
        vis[id] = 1;
//      printf("%lld %lld\n", minnum, id);
        for(long long j = 1; j <= n; j++)
            if(vis[j] == 0 && smaller2(id, j)){
                dis[j] = dis[id] + rec[id][j];
                rec2[j] = id;
            }
//      for(long long j = 1; j <= n; j++) printf("%lld ", dis[j]);
//      printf("\n");
    }
    printf("%lld\n", dis[t]);
    p(t);
    return 0;
}
