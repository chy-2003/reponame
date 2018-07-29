#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30010;
int lp, f[MAXN], lin[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1], dis[MAXN];
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; val[lp] = z; return; }
int n, x, y, z;
int maxnum, id;
void dfs(int pos, int father, int s){
    dis[pos] = s;
    for(int t = f[pos]; t; t = nxt[t]){
        if(lin[t] == father) continue;
        dfs(lin[t], pos, s + val[t]);
    }
    return;
}
void work(){
    lp = 0;
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d%d", &x, &y, &z);
        x++;y++;
        add(x, y, z);
        add(y, x, z);
    }
    memset(dis, 255, sizeof(dis));
    dfs(1, 1, 0);
    maxnum = 0;
    id = 0;
    for(int i = 1; i <= n; i++) 
        if(dis[i] > maxnum){
            maxnum = dis[i];
            id = i;
        }
    memset(dis, 255, sizeof(dis));
    dfs(id, id, 0);
    maxnum = 0;
    for(int i = 1; i <= n; i++) maxnum = max(maxnum, dis[i]);
    printf("%d\n", maxnum);
    return;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) printf("Case %d: ", i), work();
    return 0;
}

