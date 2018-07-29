#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int color[MAXN];
int lp1 = 0, f1[MAXN], lin1[MAXN << 1], nxt1[MAXN << 1];
inline void add(int x, int y) {
    lin1[++lp1] = y; nxt1[lp1] = f1[x]; f1[x] = lp1; return;
}
int n, x, y;

int lp2 = 0, f2[MAXN], lin2[MAXN << 1], nxt2[MAXN << 1];
inline void add2(int x, int y) {
    lin2[++lp2] = y; nxt2[lp2] = f2[x]; f2[x] = lp2; return;
}

int number[MAXN], used = 0;

void ruin(int pos, int fa) {
    for(int t = f1[pos]; t; t = nxt1[t]) {
        if(lin1[t] == fa) continue;
        if(color[pos] != color[lin1[t]]){
            used++;
            number[lin1[t]] = used;
            add2(number[lin1[t]], number[pos]);
            add2(number[pos], number[lin1[t]]);
        } else number[lin1[t]] = number[pos];
        ruin(lin1[t], pos);
    }
    return;
}

int dis[MAXN];
void dfs(int pos, int fa, int s) {
    dis[pos] = s;
    for(int t = f2[pos]; t; t = nxt2[t]) {
        if(lin2[t] == fa) continue;
        dfs(lin2[t], pos, s + 1);
    }
    return;
}
int maxnum, id;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &color[i]);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    number[1] = 1; used = 1;
    ruin(1, 0);
    dfs(1, 0, 0);
    maxnum = 0;
    for(int i = 1; i <= used; i++) 
        if(maxnum < dis[i]) {
            maxnum = dis[i];
            id = i;
        }
    dfs(id, 0, 0);
    maxnum = 0;
    for(int i = 1; i <= used; i++) maxnum = max(maxnum, dis[i]);
    printf("%d\n", (maxnum + 1) / 2);
    return 0;
}

