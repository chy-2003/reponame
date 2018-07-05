//XJOI 3329
#include<bits/stdc++.h>
using namespace std;
int n, first[1000010], ll, next[1000010], val[1000010];
int x, y;
void add(int x, int y){
    ll++;
    next[ll] = first[x];
    first[x] = ll;
    val[ll] = y;
    return;
}
int l, r, q[1000010], vis[1000010], dis[1000010];
void bfs(int st, int en){
    l = 0;
    r = 1;
    q[1] = st;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    vis[st] = 1;
    while(l < r){
        l++;
        for(int i = first[q[l]]; i; i = next[i]){
            if(vis[val[i]]) continue;
            r++;
            q[r] = val[i];
            vis[val[i]] = 1;
            dis[val[i]] = dis[q[l]] + 1;
            if(val[i] == en){
                printf("%d", dis[en]);
                return;
            }
        }
    }
    return;
}
int main(){
    scanf("%d", &n);
    memset(first, 0, sizeof(first));
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    scanf("%d%d", &x, &y);
    bfs(x, y);
    return 0;
}