#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
int f[1010], n, C[1010][1010];
void init() {
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = 1; i * 2 <= n; i++)
        for(int j = 0; j <= i - 1; j++)
            f[i] = (f[i] + 1LL * f[j] * f[i - j - 1] % MOD) % MOD;
    return;
}
int main() {
    scanf("%d", &n);
    init();
    int ans = 0;
    for(int i = 0; i * 2 <= n; i++)
        ans = (ans + 1LL * C[n][i * 2] * f[i] % MOD) % MOD;
    printf("%d\n", ans);
    return 0;
}

