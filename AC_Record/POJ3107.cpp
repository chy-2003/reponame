#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int lp = 0, f[50010], lin[100010], nxt[100010], size[50010];
inline void add(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int x, y;
int l = 0, rec[50010];
void dfs(int pos, int father){
    size[pos] = 1;
    int cnt = 0;
    for(int t = f[pos]; t; t = nxt[t]){
        if(lin[t] == father) continue;
        dfs(lin[t], pos);
        size[pos] += size[lin[t]];
        cnt = max(cnt, size[lin[t]]);
    }
    cnt = max(cnt, n -size[pos]);
    if(cnt <= n / 2){
        l++;
        rec[l] = pos;
    }
    return;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1, 1);
    sort(rec + 1, rec + l + 1);
    for(int i = 1; i <= l; i++) printf("%d ", rec[i]); printf("\n");
    return 0;
}

