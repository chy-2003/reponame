#include <bits/stdc++.h>
using namespace std;
int v, n1, n2, m;
int map1[510][510], rec[510][510];
int x, y;
int ret = 0, my[510], visy[510];
bool dfs(int s) {
    for(int i = 1; i <= map1[s][0]; i++) {
        if(!visy[map1[s][i]]) {
            visy[map1[s][i]] = 1;
            if(my[map1[s][i]] == -1 || dfs(my[map1[s][i]])) {
                my[map1[s][i]] = s;
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d%d%d", &v, &n1, &n2, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        if(rec[x][y]) continue;
        rec[x][y] = 1;
        map1[x][++map1[x][0]] = y;
    }
    memset(my, 255, sizeof(my));
    for(int i = 1; i <= n1; i++) {
        memset(visy, 0, sizeof(visy));
        if(dfs(i)) ret++;
    }
    printf("%d\n", min(v + 1, n1 + n2 - ret));
    return 0;
}
