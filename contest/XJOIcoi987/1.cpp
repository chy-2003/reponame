#include <bits/stdc++.h>
using namespace std;
int n, f[1010][2];
const int MOD = 12345;
int main() {
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    f[1][0] = 8;
    f[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i][0] = (f[i - 1][0] * 9 % MOD + f[i - 1][1]) % MOD;
        f[i][1] = (f[i - 1][1] * 9 % MOD + f[i - 1][0]) % MOD;
    }
    printf("%d\n", f[n][0]);
    return 0;
}

