//XJOI 3419
#include<bits/stdc++.h>
using namespace std;
long long n, k, MOD, sum, x;
long long pow(long long x){
    if(x == 0) return 1 % MOD;
    long long t = pow(x / 2);
    t = t * t % MOD;
    if(x % 2 == 1) t = t * n % MOD;
    return t;
}
int main(){
    scanf("%lld%lld%lld", &n, &k, &MOD);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        sum += x % MOD;
        sum %= MOD;
    }
    long long ans = sum * (k % MOD) % MOD;
    ans = ans * pow(k - 1) % MOD;
    printf("%lld", ans);
    return 0;
}