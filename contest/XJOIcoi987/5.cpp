#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
int n, f[1010];
int main() {
    scanf("%d", &n);
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 0; j < i; j++)
            f[i] = (f[i] + 2 * f[j] * (i - j)) % MOD;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) ans = (ans + f[i]) % MOD;
    printf("%d\n", ans);
    return 0;
}

