#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
const int MAXN = 10010, MAXM = 100010;
int n, m;
int lp, f[MAXN], lin[MAXM << 1], nxt[MAXM << 1], used[MAXM << 1];
inline void add(int x, int y) { lin[lp] = y; nxt[lp] = f[x]; f[x] = lp; lp++; return; }
int x, y;
int DFN[MAXN], LOW[MAXN], timeset;
int ansnum, ans[MAXM];
void clean() {
    memset(f, 255, sizeof(f));
    memset(used, 0, sizeof(used));
    memset(DFN, 0, sizeof(DFN));
    memset(LOW, 0, sizeof(LOW));
    timeset = 0;
    lp = 0;
    ansnum = 0;
    memset(ans, 0, sizeof(ans));
    return;
}
void dfs(int pos) {
    DFN[pos] = LOW[pos] = ++timeset;
    for(int t = f[pos]; t != -1; t = nxt[t]) {
        if(used[t]) continue;
        used[t] = 1; used[t ^ 1] = 1;
        if(DFN[lin[t]]) {
            LOW[pos] = min(LOW[pos], DFN[lin[t]]);
            continue;
        }
        dfs(lin[t]);
        LOW[pos] = min(LOW[pos], LOW[lin[t]]);
        if(LOW[lin[t]] > DFN[pos])
            ans[++ansnum] = t / 2 + 1;
    }
    return;
}
void work() {
    clean();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1);
    sort(ans + 1, ans + ansnum + 1);
    printf("%d\n", ansnum);
    for(int i = 1; i <= ansnum; i++) if(i == 1) printf("%d", ans[1]); else printf(" %d", ans[i]); 
    if(ansnum != 0) printf("\n");
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        work();
        if(i != t) printf("\n");
    }
    return 0;
}
