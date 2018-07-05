//XJOI 3406
#include<bits/stdc++.h>
using namespace std;
long long n, k;
int main(){
    scanf("%lld%lld", &n, &k);
    long long ans = 1;
    if(k >= 2) ans += (n - 1) * n / 2;
    if(k >= 3) ans += (n - 2) * (n - 1) * n / 3;
    if(k >= 4) ans += 3 * (n - 3) * (n - 2) * (n - 1) * n / 8;
    printf("%lld", ans);
    return 0;
}