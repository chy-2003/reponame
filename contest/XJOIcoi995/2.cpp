#include <cstdio>
#include <cstring>
 
long long n, sum, a[110], f[300010];
 
int main() {
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sum = 0;
    for(long long i = 1; i <= n; i++) sum += a[i];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(long long i = 1; i <= n; i++)
        for(long long j = sum; j >= a[i]; j--)
            f[j] += f[j - a[i]];
    for(long long i = 1; i <= n; i++) {
        for(long long j = 0; j <= sum - a[i]; j++)
            f[j + a[i]] -= f[j];
        long long ans = 0;
        for(long long j = 1; j <= sum; j++)
            if(f[j]) ans++;
        printf("%lld\n", ans);
        for(long long j = sum - a[i]; j >= 0; j--)
            f[j + a[i]] += f[j];
    }
    return 0;
}
