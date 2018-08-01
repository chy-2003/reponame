#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110, MAXM = 20;
int n, m, a[MAXN][MAXM];
char ch;
int dp[MAXN][220][220];
int rec[MAXN][220], rec2[MAXN][220];
int ans;
bool check1(int x, int y) {
    for(int i = 1; i <= m; i++)
        if(((x >> (i - 1)) & 1) & ((y >> (i - 1)) & 1)) return false;
    return true;
}
bool check2(int x, int y, int z) {
    for(int i = 1; i <= m; i++)
        if(((x >> (i - 1)) & 1) & (((y >> (i - 1)) & 1) | ((z >> (i - 1)) & 1))) return false;
    return true;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> ch;
            if(ch == 'P') a[i][j] = 0; else a[i][j] = 1;
        }
    for(int i = 1; i <= n; i++) {
        rec[i][0] = 0;
        for(int j = 0; j < 1 << m; j++) {
            int b = 1;
            int cnt = 0;
            for(int k = 1; k <= m; k++) {
                if(!((j >> (k - 1)) & 1)) continue;
                if(a[i][k]) {
                    b = 0;
                    break;
                }
                if(k > 1)
                    if((j >> (k - 2)) & 1) {
                        b = 0;
                        break;
                    }
                if(k > 2)
                    if((j >> (k - 3)) & 1) {
                        b = 0;
                        break;
                    }
                if((j >> (k - 1)) & 1) cnt++;
            }
            if(b == 0) continue;
            rec[i][++rec[i][0]] = j;
            rec2[i][rec[i][0]] = cnt;
        }
    }
    ans = 0;
    for(int i = 1; i <= rec[1][0]; i++) {
        dp[1][i][0] = max(dp[1][i][0], rec2[1][i]);
        ans = max(ans, dp[1][i][0]);
    }
    if(n > 1) {
        for(int i = 1; i <= rec[1][0]; i++)
            for(int j = 1; j <= rec[2][0]; j++) {
                if(check1(rec[1][i], rec[2][j])) {
                    dp[2][j][i] = max(dp[2][j][i], dp[1][i][0] + rec2[2][j]);
                    ans = max(ans, dp[2][j][i]);
                }
            }
    }
    for(int i = 3; i <= n; i++)
        for(int j = 1; j <= rec[i - 2][0]; j++)
            for(int k = 1; k <= rec[i - 1][0]; k++)
                for(int l = 1; l <= rec[i][0]; l++)
                    if(check2(rec[i][l], rec[i - 1][k], rec[i - 2][j])) {
                        dp[i][l][k] = max(dp[i][l][k], dp[i - 1][k][j] + rec2[i][l]);
                        ans = max(dp[i][l][k], ans);
                    }
    printf("%d\n", ans);
    return 0;
}
