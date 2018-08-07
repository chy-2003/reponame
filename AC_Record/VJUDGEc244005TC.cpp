#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
int tree[400010 * 32][2], used;
int n, a[400010], f[400010], g[400010];
int pre;
void add(int x) {
    int t = 1;
    for(int i = 31; i >= 0; i--) {
        if(tree[t][(x >> i) & 1] == 0) tree[t][(x >> i) & 1] = ++used;
        t = tree[t][(x >> i) & 1];
    }
    return;
}
int ask(int x) {
    int t = 1, re = 0;
    for(int i = 31; i >= 0; i--) {
        if(((x >> i) & 1) == 1) {
            if(tree[t][0]) re += 1 << i, t = tree[t][0]; else t = tree[t][1];
        }
        if(((x >> i) & 1) == 0) {
            if(tree[t][1]) re += 1 << i, t = tree[t][1]; else t = tree[t][0];
        }
    }
    return re;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    pre = 0; used = 1;
    memset(tree, 0, sizeof(tree));
    add(0);
    for(int i = 1; i <= n; i++) {
        pre ^= a[i];
        f[i] = ask(pre); add(pre);
    }
    pre = 0; used = 1;
    memset(tree, 0, sizeof(tree));
    add(0);
    for(int i = n; i >= 1; i--) {
        pre ^= a[i];
        g[i] = ask(pre); add(pre);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) f[i] = max(f[i - 1], f[i]);
    for(int i = n; i >= 1; i--) g[i] = max(g[i + 1], g[i]);
    for(int i = 1; i <= n - 1; i++) ans = max(ans, f[i] + g[i + 1]);
    printf("%d\n", ans);
    return 0;
}

