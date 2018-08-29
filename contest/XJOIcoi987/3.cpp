#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
int n, f[1010][3];
int main() {
    scanf("%d", &n);
    f[1][0] = 1; f[1][1] = 1; f[1][2] = 1;
    for(int i = 2; i <= n; i++) {
        f[i][0] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % MOD;
        f[i][1] = (f[i - 1][0] + f[i - 1][1]) % MOD;
        f[i][2] = (f[i - 1][0] + f[i - 1][2]) % MOD;
    }
    int ans = (f[n][0] + f[n][1] + f[n][2]) % MOD;
    printf("%d\n", ans);
    return 0;
}

