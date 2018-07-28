#include <bits/stdc++.h>
using namespace std;
const long long mod = 20090126;
long long dp[110][110], A[110];
long long t, n, ans;
int main(){
    dp[0][0] = 1;
    for(long long i = 1; i <= 100; i++)
        for(long long j = 1; j <= i; j++)
           dp[i][j] = (dp[i - 1][j] * j + dp[i -1][j - 1]) % mod; 
    A[0] = 1;
    for(long long i = 1; i <= 100; i++) A[i] = (A[i - 1] * i) % mod;
    scanf("%lld", &t);
    for(long long i = 1; i <= t; i++){
        scanf("%lld", &n);
        ans = 0;
        for(long long j = 1; j <= n; j++) ans = (ans + dp[n][j] * A[j] % mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}

