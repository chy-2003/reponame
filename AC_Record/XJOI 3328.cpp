//XJOI 3328
#include<bits/stdc++.h>
using namespace std;
int n, m, first[1000010], ll = 0, next[2000010], val[2000010], x, y, vis[1000010], ans = 1;
int l, r, q[1000010], color[1000010];
void bfs(int x){
    l = 0; r = 1; q[1] = x;
    vis[x] = 1; color[x] = 0;
    while(l < r){
        l++;
        for(int i = first[q[l]]; i; i = next[i]){
            if(vis[val[i]]){
                if(color[val[i]] == color[q[l]]){
                    ans = 0;
                    break;
                }
                continue;
            }
            r++;
            q[r] = val[i];
            vis[q[r]] = 1;
            color[q[r]] = (color[q[l]] + 1) % 2;
        }
    }
    return;
}
void add(int x, int y){
    ll++;
    next[ll] = first[x];
    first[x] = ll;
    val[ll] =y;
    return;
}
int main(){
    memset(first, 0, sizeof(first));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        bfs(i);
        if(ans == 0) break;
    }
    if(ans) printf("Yes"); else printf("No");
    return 0;
}