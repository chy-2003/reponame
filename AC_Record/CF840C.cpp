#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, a[310], ans;
long long b[310], l = 0;
long long dp[310][310];
long long C[310][310], A[310];
long long cnt, t;
int main(){
    scanf("%I64d", &n);
    for(long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for(long long i = 1; i <= n; i++){
        for(long long j = 2; j * j <= a[i]; j++)
            while(a[i] % (j * j) == 0) a[i] /= j * j;
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = 0;
    for(long long i = 2; i <= n + 1; i++)
        if(a[i] != a[i - 1])
            b[++l] = i - 1;


    C[0][0] = 1;
    for(long long i = 1; i <= n; i++){
        C[i][0] = 1;
        for(long long j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    A[0] = 1;
    for(long long i = 1; i <= n; i++) A[i] = (A[i - 1] * i) % mod;


    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(long long i = 1; i <= l; i++)
        for(long long j = 0; j < n; j++){
            if(dp[i - 1][j] == 0) continue;//前i组数，有j个坏对
            cnt = b[i] - b[i - 1];//cnt为当前组中数字个数，那么新产生了cnt-k对坏对
            for(long long k = 1; k <= cnt; k++)
                for(long long p = 0; p <= min(k, j); p++){//将cnt个数分成k组，并消除原先中p个坏对
                    //cnt个数有cnt!种排列方法(A[cnt]),消除的坏对有C[j][p]种选法
                    //分成k组总共有C[cnt-1][k-1]中方法
                    //消除p组坏对用了p组,还剩k-p组
                    //前面一共有b[i-1]个数,新放的可以在b[i-1]+1个位置,其中j个不能放,则总共有b[i-1]+1-j
                    //所以剩下k-p组可以放在b[i-1]+1-j个位置,共C[b[i - 1] + 1 - j][k - 1]种方案
//                    printf("i = %I64d j = %I64d k = %I64d p = %I64d\n", i, j, k, p);
                    t = dp[i - 1][j] * A[cnt] % mod * C[j][p] % mod * C[cnt - 1][k - 1] % mod * C[b[i - 1] + 1 - j][k - p] % mod;
//                    printf("%I64d\n", t);
                    dp[i][j - p + cnt - k] = (dp[i][j - p + cnt - k] + t) % mod;
                }
        }
//    for(long long i = 0; i <= l; i++){
//        for(long long j = 0; j <= n; j++) printf("%I64d ", dp[i][j]);
//        printf("\n");
//    }
    printf("%I64d\n", dp[l][0]);
    return 0;
}

