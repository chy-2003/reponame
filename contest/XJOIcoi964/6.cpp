#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int r[30], n, cnt[30];
int a[30][30], aa[30][30], dis[30];
int x;
void work() {
    memset(r, 0, sizeof(r));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i <= 23; i++) scanf("%d", &r[i]);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &x), cnt[x]++;
    int l = 0, rr = n + 1, mid;
    while(l < rr) {
        mid = (l + rr) >> 1;
        memset(a, 0, sizeof(a)); memset(aa, 0, sizeof(aa));
        for(int i = 1; i <= 23; i++) {
            aa[i - 1][i] = 1; a[i - 1][i] = 0;
            aa[i][i - 1] = 1; a[i][i - 1] = -cnt[i];
        }
        for(int i = 7; i <= 23; i++) {
            aa[i - 8][i] = 1;
            a[i - 8][i] = r[i];
        }
        for(int i = 0; i < 7; i++) {
            aa[i + 16][i] = 1; a[i + 16][i] = r[i] - mid;
        }
        aa[0][24] = 1; a[0][24] = x;
        int t = 0;
        memset(dis, 0, sizeof(dis));
        for(int i = 1; i <= 24; i++) {
            t++;
            int bb = 0;
            for(int j = 0; j < 24; j++)
                for(int k = 0; k < 24; k++) {
                    if(aa[j][k] == 0) continue;
                    if(dis[k] < dis[j] + a[j][k]) {
                        dis[k] = dis[j] + a[j][k];
                        bb = 1;
                    }
                }
            if(bb == 0) break;
        }
        if(t >= 24) l = mid + 1; else rr = mid;
    }
    if(l < n) printf("%d\n", l); else printf("No Solution！\n");
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

