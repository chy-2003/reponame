#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
int n, f[1010];
int main() {
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i - 2 >= 0) f[i] = (f[i - 1] + 2 * f[i - 2] % MOD) % MOD;
        else f[i] = f[i - 1];
    }
    printf("%d\n", f[n]);
    return 0;
}

