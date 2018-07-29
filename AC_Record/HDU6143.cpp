#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, m, ans;
long long dp[2010][2010], c[2010][2010], A[2010];
long long power(int x, int p){
    if(p == 0) return 1;
    long long t = power(x, p / 2);
    t = (t * t) % mod;
    if(p % 2 == 1) t = (t * x) % mod;
    return t;
}
void work(){
    scanf("%lld%lld", &n, &m);
    ans = 0;
    for(int i = 1; i <= min(n, m); i++) ans = (ans + dp[n][i] * A[i] % mod * c[m][i] % mod * power(m - i, n) % mod) % mod;
    printf("%lld\n", ans);
    return;
}
int main(){
    dp[0][0] = 1;
    for(int i = 1; i <= 2000; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j % mod) % mod;
    c[0][0] = 1;
    for(int i = 1; i <= 2000; i++){   
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    A[0] = 1;
    for(int i = 1; i <= 2000; i++) A[i] = (A[i - 1] * i) % mod;
//    for(int i = 1; i <= 5; i++){
//        for(int j = 1; j <= i; j++) printf("%lld ", dp[i][j]); printf("\n");
//    }
//    printf("*\n");
    int t;
    scanf("%d", &t);
//    printf("%d\n", t);
    for(int i = 1; i <= t; i++) {
//        printf("*\n");
        work();
//        printf("*\n");
    }
    return 0;
}

