#include <bits/stdc++.h>
using namespace std;
int n, m, a[600010], l, x, dis[3010];
int gcd;
int get_gcd(int x, int y) {
    int m = x % y;
    while(m) { x = y; y = m; m = x % y; }
    return y;
}
int vis[3010], ans = 0;
int lq = 0, q[3010], inq[3010], ref[3010];
void qpush(int x) {
    lq++;
    q[lq] = x;
    ref[x] = lq;
    int id = lq;
    while(id > 1 && dis[q[id]] < dis[q[id >> 1]]) {
        swap(ref[q[id]], ref[q[id >> 1]]);
        swap(q[id], q[id >> 1]);
        id >>= 1;
    }
    return;
}
void qrefresh(int x) {
    while(x > 1 && dis[q[x]] < dis[q[x >> 1]]) {
        swap(ref[q[x]], ref[q[x >> 1]]);
        swap(q[x], q[x >> 1]);
        x >>= 1;
    }
    return;
}
void qpop() {
    ref[q[1]] = 0;
    ref[q[lq]] = 1;
    q[1] = q[lq];
    lq--;
    int id = 1;
    while(id * 2 <= lq) {
        if(id * 2 + 1 > lq) {
            if(dis[q[id * 2]] < dis[q[id]]) {
                swap(ref[q[id]], ref[q[id * 2]]);
                swap(q[id], q[id * 2]);
                break;
            } else break;
        } else {
            if(dis[q[id * 2]] < dis[q[id * 2 + 1]]) {
                if(dis[q[id * 2]] < dis[q[id]]) {
                    swap(ref[q[id]], ref[q[id * 2]]);
                    swap(q[id], q[id * 2]);
                    id = id * 2;
                } else break;
            } else {
                if(dis[q[id * 2 + 1]] < dis[q[id]]) {
                    swap(ref[q[id]], ref[q[id * 2 + 1]]);
                    swap(q[id], q[id * 2 + 1]);
                    id = id * 2 + 1;
                } else break;
            }
        }
    }
    return;
}
int main() {
    l = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[++l] = x;
        for(int j = 1; j <= m; j++)
            if(x >= j) a[++l] = x - j;
    }
    sort(a + 1, a + l + 1);
    if(a[1] <= 1) {
        printf("-1\n");
        return 0;
    }
    gcd = a[1];
    for(int i = 2; i <= l; i++) gcd = get_gcd(gcd, a[i]);
    if(gcd > 1) {
        printf("-1\n");
        return 0;
    }


    memset(dis, 255, sizeof(dis));
    for(int i = 1; i <= l; i++)
        if(dis[a[i] % a[1]] == -1 || dis[a[i] % a[1]] > a[i])
            dis[a[i] % a[1]] = a[i];
    memset(vis, 0, sizeof(vis));
    memset(inq, 0, sizeof(inq));
    memset(ref, 0, sizeof(ref));
    for(int i = 0; i < a[1]; i++)
        if(dis[i] != -1) {
            inq[i] = 1;
            qpush(i);
        }
    while(lq) {
        int t = q[1]; qpop();
        vis[t] = 1;
        for(int i = 1; i <= l; i++) {
            if(dis[(t + a[i]) % a[1]] == -1 || dis[(t + a[i]) % a[1]] > dis[t] + a[i]) {
                dis[(t + a[i]) % a[1]] = dis[t] + a[i];
                if(inq[(t + a[i]) % a[1]]) qrefresh(ref[(t + a[i]) % a[1]]); else {
                    qpush((t + a[i]) % a[1]);
                    inq[(t + a[i]) % a[1]] = 1;
                }
            }
        }
    }
    for(int i = 0; i < a[1]; i++) {
        if(dis[i] == -1) {
            printf("-1\n");
            return 0;
        }
        ans = max(ans, dis[i] - a[1]);
    }
    if(ans == 0) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}
