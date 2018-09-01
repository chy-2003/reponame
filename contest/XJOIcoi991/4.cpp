#include <bits/stdc++.h>
using namespace std;
int n, a[110], b[110];
int f[110][110];
int main() {
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for(int p = 2; p <= n; p++)
        for(int i = 1; i <= n - p + 1; i++) {
            int j = i + p - 1;
            f[i][j] = 2147483647;
            for(int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[i] * b[k] * b[j]);
        }
    printf("%d\n", f[1][n]);
    return 0;
}
