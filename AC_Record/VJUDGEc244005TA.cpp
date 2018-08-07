#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100010, MAXM = 100010, MAXLOG = 32;
int tree[MAXN * 32][2], usedspace;
int n, m, x;
void work() {
    memset(tree, 0, sizeof(tree));
    usedspace = 1;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        int t = 1;
        for(int j = MAXLOG - 1; j >= 0; j--) {
            if(tree[t][(x >> j) & 1] == 0) tree[t][(x >> j) & 1] = ++usedspace;
            t = tree[t][(x >> j) & 1];
        }
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        int ans = 0;
        int t = 1;
        for(int j = MAXLOG - 1; j >= 0; j--) {
            if(((x >> j) & 1) == 1) {
                if(tree[t][0]) t = tree[t][0]; else ans += 1 << j, t = tree[t][1];
            }
            if(((x >> j) & 1) == 0) {
                if(tree[t][1]) ans += 1 << j, t = tree[t][1]; else t = tree[t][0];
            }
        }
        printf("%d\n", ans);
    }
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) printf("Case #%d:\n", i), work();
    return 0;
}

