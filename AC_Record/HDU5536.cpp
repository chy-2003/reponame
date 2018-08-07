#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, a[1010], tree[32010][2], usedspace, cnt[32010];
void add(int x) {
    int t = 1; cnt[t]++;
    for(int i = 31; i >= 0; i--) {
        if(tree[t][(x >> i) & 1] == 0) tree[t][(x >> i) & 1] = ++usedspace;
        t = tree[t][(x >> i) & 1]; cnt[t]++;
    }
    return;
}
void del(int x) {
    int t = 1; cnt[t]--;
    for(int i = 31; i >= 0; i--) {
        t = tree[t][(x >> i) & 1]; cnt[t]--;
    }
    return;
}
int ask(int x) {
    int t = 1, re = 0;
    for(int i = 31; i >= 0; i--) {
        if(((x >> i) & 1) == 0) {
            if(tree[t][1] > 0 && cnt[tree[t][1]] > 0) re += 1 << i, t = tree[t][1]; else t = tree[t][0];
        }
        if(((x >> i) & 1) == 1) {
            if(tree[t][0] > 0 && cnt[tree[t][0]] > 0) re += 1 << i, t = tree[t][0]; else t = tree[t][1];
        }
    }
    return re;
}
int ans;
void work() {
    memset(tree, 0, sizeof(tree)); usedspace = 1;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) add(a[i]);
    ans = 0;
    for(int i = 1; i < n; i++) 
        for(int j = i + 1; j <= n; j++) {
            del(a[i]); del(a[j]);
            ans = max(ans, ask(a[i] + a[j]));
            add(a[i]); add(a[j]);
        }
    printf("%d\n", ans);
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

