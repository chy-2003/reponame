//XJOI 3596
#include <bits/stdc++.h>
using namespace std;
long long m, n, p, ans = 1;
long long power(long long a, long long t, long long p){
    if(t == 0) return 1;
    long long tt = a % p;
    long long ans = 1;
    while(t){
        if(t & 1) ans = (ans * tt) % p;
        tt = (tt * tt) % p;
        t >>= 1;
    }
    return ans;
}
int main(){
    scanf("%lld", &m);
    n = m; m *= 2; p = 1000000007;
    if(n > m / 2) n = m - n;
    for(int i = (m - n + 1); i <= m; i++) ans = (ans * i) % p;
    for(int i = 1; i <= n; i++) ans = (ans * power(i, p - 2, p)) % p;
    ans = (ans * power(n + 1, p - 2, p)) % p;
    printf("%lld", ans);
    return 0;
}