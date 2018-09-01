#include <bits/stdc++.h>
using namespace std;
int rec[310][310], P, N;
int mx[310], my[310], visy[310];

bool dfs(int x) {
    for(int i = 1; i <= rec[x][0]; i++) 
        if(visy[rec[x][i]] == 0) {
            visy[rec[x][i]] = 1;
            if(my[rec[x][i]] == -1 || dfs(my[rec[x][i]])) {
                mx[x] = rec[x][i];
                my[rec[x][i]] = x;
                return true;
            }
        }
    return false;
}

void work() {
    P = N = 0;
    memset(rec, 0, sizeof(rec));
    scanf("%d%d", &P, &N);
    memset(rec, 0, sizeof(rec));
    for(int i = 1; i <= P; i++) {
        scanf("%d", &rec[i][0]);
        for(int j = 1; j <= rec[i][0]; j++) 
            scanf("%d", &rec[i][j]);
    }
    int cnt = 0;
    memset(mx, 255, sizeof(mx));
    memset(my, 255, sizeof(my));
    for(int i = 1; i <= P; i++) {
        memset(visy, 0, sizeof(visy));
        if(dfs(i)) cnt++;
    }
    if(cnt == P) printf("YES\n"); else printf("NO\n");
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

