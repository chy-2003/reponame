//XJOI 3400
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k, a, b;
    long long ans = 0;
    scanf("%lld%lld%lld", &k, &a, &b);
    if(a > b) swap(a, b);
    if(a <= 0 && 0 <= b) ans++;
    if(a == 0) a++;
    if(b == 0) b--;
    if(a > 0) ans += b / k - (a - 1) / k; else
    if(b < 0) ans += (-a) / k - (-b - 1) / k; else
    ans += (-a) / k + (b) / k;
    printf("%lld", ans);
    return 0;
}