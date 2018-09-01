#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
int ans, n, m;
int a[40][40];
int rec_dfs[40];
bool check() {
    for(int i = 1; i <= n; i++) 
        if(rec_dfs[i] != m) 
            return false;
    return true;
}
inline int h(int x) {
    int ans = (x % m - 1) + (m + m - 1) * ((x + m - 1) / m - 1);
    if(x % m == 0) ans += x % m;
    return ans;
}
void dfs(int used, bool possible, int res) {
    if(used + h(res) >= ans) return; 
    if(res == 0 && !possible) return;
    if(possible && check()) {
        ans = used;
        return;
    }
    int i = 1, j, k, l = m, x, _, _o, rec_min, delta;
    while(i <= n) {
        j = i;
        while(rec_dfs[j] == rec_dfs[i] && j <= n) {
            k = rec_dfs[i] + 1;
            rec_min = INF;
            while(k <= l) {
                x = a[j][k] - a[j][rec_dfs[i]] - a[i - 1][k] + a[i - 1][rec_dfs[i]];
                rec_min = min(rec_min, x);
                if(x == 1) {
                    _ = rec_dfs[i];
                    for(int t = i; t <= j; t++) rec_dfs[t] = k;
                    delta = j - i + 1 + k - _;
                    if(k == m) delta -= j - i + 1;
                    if(j == n) delta -= k - _;
                    if(k == m) 
                        dfs(used + delta, true, res - 1);
                    else 
                        dfs(used + delta, false, res - 1);
                    for(int t = i; t <= j; t++) rec_dfs[t] = _;
                }
                if(x >= 2) break;
                k++;
            }
            if(rec_min >= 2) break;
            j++;
        }
        while(rec_dfs[j] == rec_dfs[i] && j <= n) j++;
        i = j;
        l = rec_dfs[i - 1];
    }
    return;
}
int count() {
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]) ans++;
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    memset(rec_dfs, 0, sizeof(rec_dfs));
    ans = INF;
    dfs(0, false, count());
    printf("%d\n", ans);
    return 0;
}

