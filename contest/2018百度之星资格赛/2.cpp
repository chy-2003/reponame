#include <bits/stdc++.h>
using namespace std;
int n, q;
char s[100010];
int delta[100010][26];
int x, y;
void work() {
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    memset(delta, 0, sizeof(delta));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) delta[i + 1][j] = delta[i][j];
        delta[i + 1][s[i] - 'A']++;
    }
    for(int i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        for(int j = 0; j < 26; j++)
            if(delta[y][j] != delta[x - 1][j]) {
                printf("%d\n", delta[y][j] - delta[x - 1][j]);
                break;
            }
    }
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) printf("Case #%d:\n", i), work();
    return 0;
}

