//XJOI 3299
#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
int main(){
    long long ans = 0;
    scanf("%lld%lld%lld", &n, &m, &k);
    if(n + m - 2 < k){
        printf("-1");
        return 0;
    }
    if(n - 1 > k) ans = m * (n / (k + 1));
    else ans = m / (k - n + 2);
    if(m - 1 > k) ans = max(n * (m / (k + 1)), ans);
    else ans = max(ans, n / (k - m + 2));
    printf("%lld", ans);
    return 0;
}