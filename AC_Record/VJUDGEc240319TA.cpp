#include<bits/stdc++.h>
using namespace std;
int n, q;
int lp = 0, f[300010], lin[600010], nxt[600010];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int size[300010], ans[300010];
int father[300010];
void dfs(int fa, int pos){
    int bo = 0;
    father[pos] = fa;
    size[pos] = 1;
    for(int t = f[pos]; t; t = nxt[t]){
        if(lin[t] == fa) continue;
        dfs(pos, lin[t]);
        size[pos] += size[lin[t]];
    }
    for(int t = f[pos]; t; t = nxt[t]){
        if(lin[t] == fa) continue;
        if(size[lin[t]] > size[pos] / 2){
            for(int k = ans[lin[t]]; k != pos; k = father[k])
                if(size[pos] - size[k] <= size[pos] / 2){
                    ans[pos] = k;
                    break;
                }
            bo = 1;
            break;
        }
    }
    if(bo == 0) ans[pos] = pos;
    return;
}
int main(){
    scanf("%d%d", &n, &q);
    for(int i = 2; i <= n; i++){
        int x; scanf("%d", &x);
        add(i, x); add(x, i);
    }
    dfs(1, 1);
    for(int i = 1; i <= q; i++){
        int x; scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}

