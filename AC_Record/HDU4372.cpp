#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[2010][2010], C[2010][2010];
int n, f, b;
int main(){
    dp[0][0] = 1;
    for(int i = 1; i <= 2000; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = ((long long)(i - 1) * dp[i - 1][j] % mod + dp[i - 1][j - 1]) % mod;
    C[0][0] = 1;
    for(int i = 1; i <= 2000; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d", &n, &f, &b); 
        printf("%lld\n", C[f + b - 2][f - 1] * dp[n - 1][f + b - 2] % mod);
    }
    return 0;
}

