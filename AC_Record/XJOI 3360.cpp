//XJOI 3360
#include<bits/stdc++.h>
using namespace std;
int x, y;
int n, first[100010], l, val[200010], next[200010];
int rec[2], pos[100010], now[100010], ans, vis[100010];
void add(int x, int y){
    l++;
    next[l] = first[x];
    val[l] = y;
    first[x] = l;
    return;
}
void work(int x, int depth){
    vis[x] = 1;
    int b = 0;
    if(pos[x] != ((now[x] + rec[depth % 2]) % 2)){
        ans++;
        b = 1;
        rec[depth % 2] = (rec[depth % 2] + 1) % 2;
    }
    int l = first[x];
    while(l){
        if(!vis[val[l]]) work(val[l], depth + 1);
        l = next[l];
    }
    if(b){
        rec[depth % 2] = (rec[depth % 2] + 1) % 2;
    }
    return;
}
int main(){
    scanf("%d", &n);
    memset(first, 0, sizeof(first));
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &now[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &pos[i]);
    ans = 0;
    memset(vis, 0, sizeof(vis));
    work(1, 1);
    printf("%d\n", ans);
    return 0;
}