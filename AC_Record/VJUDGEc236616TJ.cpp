#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010, MAXM = 200010, MAXDEEP = 15;
int n, f[MAXN], nex[MAXN << 1], lin[MAXN << 1], x, y, lp = 0, deep[MAXN], size[MAXN], t;
int d[MAXN][MAXDEEP];
int m, lca, xx, yy, len;

void add(int x, int y){ lp++; nex[lp] = f[x]; lin[lp] = y; f[x] = lp; return; }

void tree_build(int father, int id){
    deep[id] = deep[father] + 1;
    d[id][0] = father;
    for(int i = 1; i < MAXDEEP; i++) d[id][i] = d[d[id][i - 1]][i - 1];
    int t = f[id];
    while(t){
        if(lin[t] != father) {
            tree_build(id, lin[t]);
            size[id] += size[lin[t]];
        }
        t = nex[t];
    }
    size[id]++;
    return;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for(int i = 0; i < MAXDEEP; i++) d[1][i] = 1; 
    deep[1] = 0;
    tree_build(1, 1);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        if(x == y){
            printf("%d\n", n);
            continue;
        }
        xx = x; yy = y;
        if(deep[x] < deep[y]){ swap(x, y); swap(xx, yy); }
        if(!(deep[x] == deep[y])){
            for(int j = MAXDEEP - 1; j >= 0; j--)
                if(deep[d[x][j]] >= deep[y]) x = d[x][j];
        }
        if(x != y){
            for(int j = MAXDEEP - 1; j >= 0; j--)
                if(d[x][j] != d[y][j]){
                    x = d[x][j]; y = d[y][j];
                }
            lca = d[x][0];
        } else lca = x;

        len = deep[xx] + deep[yy] - 2 * deep[lca] + 1;
        if(!(len & 1)){
            printf("0\n");
            continue;
        } else{
            if(deep[xx] != deep[yy]){
                len = (len - 1) / 2;
                t = xx;
                for(int j = MAXDEEP - 1; j >= 0; j--)
                    if(deep[d[t][j]] >= deep[xx] - len) t = d[t][j];
                x = xx;
                for(int j = MAXDEEP - 1; j >= 0; j--)
                    if(deep[d[x][j]] >= deep[t] + 1) x = d[x][j];
                printf("%d\n", size[t] - size[x]);
            } else{
                printf("%d\n", size[1] - size[x] - size[y]);
            }
        }
    }
    return 0;
}
