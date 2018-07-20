#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2010, MAXM = 3010;
int n, m, dis[MAXN], X[MAXM << 1], Y[MAXM << 1], val[MAXM << 1], num;
int x, y, z;
int vis[MAXN];


void work(){
    num = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        num++;
        scanf("%d%d%d", &X[num], &Y[num], &val[num]);
        if(val[num] >= 0){
            num++;
            Y[num] = X[num - 1]; X[num] = Y[num - 1]; val[num] = val[num - 1];
        }
    }
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dis[1] = 0;
    int cnt = 0;
    int change = 0;
    for(int i = 1; i <= n; i++){
        change = 0;
        for(int j = 1; j <= num; j++){
            if(vis[X[j]] == 0) continue;
            if(vis[Y[j]] == 0){
                dis[Y[j]] = dis[X[j]] + val[j];
                vis[Y[j]] = 1;
                change = 1;
            } else
            if(dis[Y[j]] > dis[X[j]] + val[j]){
                dis[Y[j]] = dis[X[j]] + val[j];
                change = 1;
            }
        }
        if(change == 0) break;
        cnt++;
    }
    if(cnt == n) printf("YE5\n"); else printf("N0\n");
    return;
}


int main(){
    int t; scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

