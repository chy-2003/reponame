//XJOI 3388
#include<bits/stdc++.h>
using namespace std;
long long n, m, ans;
int main(){
    ans = 0;
    scanf("%lld%lld", &n, &m);
    for(long long i = 2; i <= n; i += 2)
     for(long long j = 2; j <= m; j += 2)
      ans += (n - i + 1) * (m - j + 1);
    printf("%lld", ans);
    return 0;
}